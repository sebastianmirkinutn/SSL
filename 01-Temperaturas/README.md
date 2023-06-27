# Trabajo Práctico 01 - Temperaturas
*Sebastián Mirkin* smirkin@frba.utn.edu.ar

Para generar los ejecutables, correr el comando make dentro de la terminal de Mingw64

## conversion.exe

### Descripción

Toma los límites y pasos por argumento y ejecuta de forma secuencial las tablas de conversión de Celsius a Farenheit y viceversa.

### Comando de ejecución

 ./conversion.exe *base* *tope* *pasos*

## conversionTests.exe

### Descripción

Utiliza constantes como casos de prueba para *conversion.exe*, tomando la base en 0, el tope en 300 y los pasos en 20.

### Comando de ejecución

./conversion.exe *base* *tope* *pasos*

## tablasDeConversion.exe

### Descripción

Obtiene los límites, pasos y la selección de la salida por argumento. Esta última se define con la siguiente lista:

+ 1: Ambas tablas
+ 2: Tabla de Celcius
+ 3: Tabla de Farenheit
+ n: Aborta la ejecución

### Comando de ejecución

./tablasDeConversion.exe *base* *tope* *pasos* *selección*