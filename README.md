# crescente
3D Printer for mechanical metamaterials

Para poder cumplir con el proceso impresión, es necesario que se tomen ciertas desiciones previas sobre la forma y composición de la muestra requerida, para ello es necesario los siguientes materiales. 

Materiales:
- Fluido matriz: Definir polímero a ocupar como fluido matriz, se recomienda fuertemente el uso de Vinyl Polisiloxano (VPS) de la marca Zhemark, dado el control que se puede conseguir con este polímero. Queda a definición del usuario, que tipo de VPS ocupará, puesto que existen múltiples opciones según el grado de elasticidad.
- Fluido de inyección: DEfinir que tipo de fluido se va a inyectar o de que fluido quieren formar las gotas dentro del material, esto queda a criterio del usuario con la observación de que dicho fluido debe cumplir con cierto nivel de viscosidad para que el método de impresión propuesto funcione.
- Recipiente: Dependiendo de que forma se requiera la muestra, se debe escoger el tipo de recipiente, recordando que el polímero al estar inicialmente en forma líquida, este tomará la forma del recipiente en el cual se deposite.
- Arreglo de agujas: De la mano con el recipiente y relacionado con la forma final que se requiere tenga la muestra, se debe definir la forma del arreglo de agujas, este puede ser el que se desea, no hay grandes limitaciones en este tema, puede ser un arreglo lineal, triangular, cuadrado, hexagonal, etc. Para esto, solamente es necesario diseñar y construir la pieza necesaria para conectar las agujas con las mangueras que vienen de las bombas de jeringa.
- Agujas: Tambíen de la mano con los puntos anteriores, es necesario escoger el tipo de aguja que se querrá o necesitará ocupar, este tamaño tiene directa relación con el rango de tamaños posibles para las gotas.
- Parpametros código: esto no es un material en sí, pero es un paso necesario para poder imprimir luego; es necesario que se defina el tamaño deseado de las gotas, puesto que con ello se podrá definir la velocidad de inyección y el caudal a inyectar, además de definir que tan separadas quieren que queden las gotas para definir la amplitud que tendrá el movimiento zig-zag. Modificar esto en el codigo de la impresora y subirlo a la placa. 
- Centrifugadora*: Se recomienda contar con una centrifugadora para asegurar una mezcla homogenea del polímero, puesto que asi el proceso de polimerización ocurrirá al mismo tiempo en toda la muestra.
- Horno*: Dependiendo del tipo de polímero que se este utilizando, es probable que se necesite curar la muestra a una temperatura cercana a los 150-180°, por lo que un horno es necesario para completar el proceso de impresión. Para estos casos, se recomienda encontrar un par de fluidos (matriz-de inyeccción) que posean densidades similares, dado que si existen diferencias entre ellos, sumado al tiempo extra necesario para curar el polímero, el patrón de gotas puede decantar en el recipiente, dejando inutilizable la muestra.

Proceso de impresión: 
1° paso: 
Preparar el recipiente: usualmente se ocupa un recipiente formado por dos piezas, el cuerpo y una base separada, esto para facilitar la extracción de la muestra al final del proceso. Para unir ambas partes, se utiliza una mezcla de 10 gramos de VPS ( 5 gramos de catalizador y 5 gramos de base), se mezclan en la centrofugadora y se ocupan como pegamente entre ambas partes. Procurar que quede una capa suficiente de VPS en los bordes, para que no se derrame el polímero que ocuparemos para imprimir. Dejar secar por aproximadamente 10 min. 
2° paso: 
Una vez subido el código y definido el caudal en las bombas de jeringa, 
