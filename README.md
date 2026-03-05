

Christian Andres Morales Garcia
NRC-2684

Descripción del ejercicio
El ejercicio propuesto busca la creacion de un diagrama de flujo en base al codigo creado para el DEBER1 de la clase de ejercicios de C++.

Este programa en C++ permite realizar conversiones entre dos divisas utilizando una tasa de cambio ingresada por el usuario. El sistema solicita al usuario ingresar el código de las divisas, la tasa de cambio y el monto que desea convertir. Posteriormente calcula el valor equivalente en la divisa cotizada y muestra un resumen de la conversión en un formato estructurado denominado Market Snapshot.
El programa también incluye validaciones para asegurar que las entradas ingresadas por el usuario sean correctas, como verificar que las divisas tengan exactamente tres letras y que los valores numéricos sean positivos. Además, permite realizar múltiples conversiones dentro de la misma ejecución del programa.

Explicación de la lógica del programa

El programa inicia estableciendo una variable de control que permite repetir el proceso de conversión mientras el usuario lo desee. Luego solicita al usuario ingresar la divisa base y la divisa cotizada, verificando que cada una tenga exactamente tres letras alfabéticas.
Posteriormente se solicita la tasa de cambio entre ambas divisas, asegurando que sea un número positivo. Después el usuario ingresa el monto que desea convertir en la divisa base. Con estos datos el programa realiza el cálculo de la conversión multiplicando el monto base por la tasa de cambio. 
Una vez realizado el cálculo, el programa solicita un timestamp, que representa el momento en que se realizó la conversión. Finalmente se muestra un resumen llamado Market Snapshot, donde se presentan el par de divisas, la tasa de cambio utilizada, el monto base ingresado y el monto convertido. Al finalizar, el programa pregunta al usuario si desea realizar otra conversión. Si la respuesta es afirmativa, el proceso se repite; en caso contrario, el programa termina.
