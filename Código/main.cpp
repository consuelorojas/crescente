#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Stepper.h>

//LCD
int lcdCols = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd;

// Task Hanlders
TaskHandle_t AxisXcodeTask;
TaskHandle_t AxisYcodeTask;

// Stepper Pins
#define IN1 4 //   PUL-X
#define IN2 16 //   DIR-X

#define IN3 15
#define IN4 2

// Stepper Constants
const int stepsPerRevolution_X = 1000;
const int stepsPerRevolution_Y = 1000;

// Printing Constants
const int stepsX = 1000;
const int stepsY = 1000;


// Stepper Objects
Stepper axisX(stepsPerRevolution_X, IN1, IN2);//, EN1);
Stepper axisY(stepsPerRevolution_Y, IN3, IN4);//, EN2);


//keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; 

// Keypad Pins
uint8_t rowPins[COLS] = {13, 12, 14, 27}; // Pins connected to R1, R2, R3, R4
uint8_t colPins[ROWS] = {26, 25,33, 32}; // Pins connected to C1, C2, C3, C4

// Keypad Object
Keypad keypad = Keypad( makeKeymap(keys), colPins, rowPins, ROWS, COLS );

// Finite State Machine
enum state {WAITING, LOOPING};
state current_state = WAITING;

// Exit Key
const char EXITKEY = 'A';

// Keypad Event Code
void keypadEvent(KeypadEvent key){
  switch(keypad.getState()){
    case PRESSED:
      switch(key){
        case 'A': // Exit Key
          lcd.clear();
          lcd.print("Crescente");
          current_state = WAITING;
          break;
        case 'C': // Loop Key
          lcd.clear();
          lcd.setCursor(4,1);
          lcd.print("printing");
          current_state = LOOPING;
          break;
      }
      break;
  }
}

// Forward Movement
void forward(Stepper Axis, int steps){
  Axis.step(steps);
  return;
}

// Backward Movement
void backward(Stepper Axis, int steps){
  Axis.step(-steps);
  return;
}

// Axis X Code
void X_loop(Stepper axis, int stepsX){

    forward(axis, 5 * stepsX);
    delay(3);
    backward(axis, 5 * stepsX);
    delay(3);

}

void AxisXcode(void * parameter){
  for(;;){
    char key = keypad.getKey();

    switch(current_state){
        case WAITING:
        
            if (key == '4'){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Forward");
                lcd.setCursor(0,1);
                lcd.print("4000 steps");
                forward(axisX, 4000);
            }
            if (key == '7'){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.println("Backward");
                lcd.setCursor(0,1);
                lcd.println("4000 steps");
                backward(axisX, 4000);
                
            }
            break;
        case LOOPING:
            X_loop(axisX, stepsX);
            break;
    }
  }
}

// Axis Y Code
void Y_loop(Stepper axis, int stepsY){
    forward(axis,stepsY);
}


void setup(){

    axisX.setSpeed(2000);
    axisY.setSpeed(1500);
    keypad.addEventListener(keypadEvent);
    //keypad.setDebounceTime(50);

    lcd.begin(16,2);
    lcd.clear();
    lcd.backlight();
    lcd.println("Crescente");
    delay(2000);

    xTaskCreatePinnedToCore(
        AxisXcode,   /* Task function. */
        "AxisXcode", /* name of task. */
        10000,       /* Stack size of task */
        NULL,        /* parameter of the task */
        1,           /* priority of the task */
        &AxisXcodeTask, /* Task handle to keep track of created task */
        1);          /* pin task to core 0 */
}


void loop(){
  char key = keypad.getKey();

    switch(current_state){
        case WAITING:
       
            if (key == '3'){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Up");
                lcd.setCursor(0,1);
                lcd.print("4000 steps");
                forward(axisY, 4000);
                
            }
            if (key == '6'){
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Down");
                lcd.setCursor(0,1);
                lcd.print("4000 steps");
                backward(axisY, 4000);
            }
            break;
        case LOOPING:
            Y_loop(axisY, stepsY);
            
            break;
    }

}