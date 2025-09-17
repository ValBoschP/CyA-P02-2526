# CyA-P02-2526

# PRÁCTICA 2 - Cadenas y lenguajes

## Cómo compilar y ejecutar el programa

Es necesario instalar 'make' y 'cmake'.
En el mismo directorio de la práctica se debe poner en línea de comando lo siguiente:

```
$ make clean
$ make build
$ ./build/bin/p02_strings filein.txt fileout.txt opcode
```

ó

```
$ make reload
$ ./build/bin/p02_strings filein.txt fileout.txt opcode
```

## Ejercicio práctico

Teniendo en cuenta las propiedades de las cadenas y el comportamiento de las mismas, se propone desarrollar un programa en C++ que dado un fichero de entrada con la especificación de cadenas junto con sus respectivos alfabetos, realice un conjunto de comprobaciones básicas sobre ellas. Para ser coherentes con las definiciones anteriores, cabe destacar que en aquellas operaciones sobre cadenas en las que el resultado obtenido sea un conjunto de cadenas, deberíamos manejar dicho resultado como un lenguaje.

El programa recibirá por línea de comandos el nombre del fichero de entrada, el nombre del fichero de salida y un código de operación:

```console
./p02_strings filein.txt fileout.txt opcode
```

El comportamiento del programa al ejecutarse en línea de comandos debiera ser similar al de los comandos de Unix. Así por ejemplo, si se ejecuta el programa sin parámetros, se debería obtener información sobre el uso correcto del programa:

```console
$ ./p02_strings
Modo de empleo: ./p02_strings filein.txt fileout.txt opcode
Pruebe ’./p02_strings --help’ para más información.
```

La opción _**--help**_ en línea de comandos ha de producir que se imprima en pantalla un breve texto explicativo del funcionamiento del programa. Una información que puede ser de especial ayuda para los usuarios del programa sería precisamente el formato de los ficheros así como el significado de los códigos de operación.

El fichero de entrada tendr´a en cada l´ınea la especificaci´on de una cadena de entrada. Cada cadena de entrada vendr´a seguida por una secuencia de s´ımbolos que representa el alfabeto sobre el que se ha definido la cadena correspondiente. En el ejemplo siguiente tenemos la cadena abbab definida sobre el alfabeto {a, b}, la cadena 6793836 definida sobre el alfabeto {1, 2, 3, 4, 5, 6, 7, 8, 9}, y la cadena hola definida sobre el alfabeto {a, h, l, o}:

```
abbab ab
6793836 123456789
hola ahlo
```

En función del código de operación, se aplicará una determinada operación a cada una de las cadenas de entrada, escribiendo el resultado en el fichero de salida. A continuación, se describe el comportamiento para cada uno de los códigos de operación, enumerados desde el 1 hasta el 5.

**1.** **_Alfabeto:_** escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada. El fichero de salida asociado a la entrada del ejemplo anterior sería el siguiente:

```
{a, b}
{3, 6, 7, 8, 9}
{a, h, l, o}
```

**2. _Longitud:_** escribir en el fichero de salida la longitud de cada cadena de entrada. Es decir, si se escogiera el código 1, asociado al cálculo de la longitud de la cadena, el fichero de salida asociado a la entrada del ejemplo anterior sería el siguiente:

```
5
7
4
```

**3. _Inversa:_** escribir en el fichero de salida la inversa de cada cadena de entrada. En este caso, la salida sería la siguiente:

```
babba
5383976
aloh
```

**4. _Prefijos:_** escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente. Tal y como hemos mencionado, dichos conjuntos de cadenas conformarán un lenguaje y, por tanto, se representarán y se visualizarán como tales. Para la entrada de ejemplo, la salida sería similar a la siguiente:

```
{&, a, ab, abb, abba, abbab}
{&, 6, 67, 679, 6793, 67938, 679383, 6793836}
{&, h, ho, hol, hola}
```

**5. _Sufijos:_** escribir en el fichero de salida el conjunto de cadenas que son sufijos de cada cadena de entrada correspondiente. Al igual que en el caso anterior, dichos conjuntos de cadenas conformarán un lenguaje y, por tanto, se representarán y se visualizarán como tales. Para la entrada de ejemplo, la salida sería similar a la siguiente:

```
{&, b, ab, bab, bbab, abbab}
{&, 6, 36, 836, 3836, 93836, 793836, 6793836}
{&, a, la, ola, hola}
```

En relación a los resultados anteriores, téngase en cuenta que las cadenas de los conjuntos se están mostrando de forma ordenada en relación a la longitud de las mismas. El resultado sería diferente si se hubiera optar por hacer una ordenación basada en la comparación alfanumérica de las cadenas.
