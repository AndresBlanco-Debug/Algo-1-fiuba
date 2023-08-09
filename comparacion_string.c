#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*Escribir un programa modular que solicite el ingreso de dos palabras y luego
muestre las mismas según la longitud de cada una de ellas, mostrando primero
la de menor longitud.
A igualdad de longitud, mostrar primero la menor de las dos, en términos de
orden alfabético.
Las palabras tienen una longitud máxima de 15 caracteres.*/

typedef char t_cadena[15];

void comparar_palabras(t_cadena palabra_1, t_cadena palabra_2) {
    int longitud_1 = strlen(palabra_1);
    int longitud_2 = strlen(palabra_2);
    t_cadena temporal;

    if (longitud_1 > longitud_2) {
        printf("las palabras en orden son: %s, %s", palabra_2, palabra_1);
    } else if (longitud_1 == longitud_2) {
        if (strcmp(palabra_1, palabra_2) > 0) {
            // No es necesario el uso de memcpy, simplemente podemos intercambiar las palabras directamente.
            strcpy(temporal, palabra_1);
            strcpy(palabra_1, palabra_2);
            strcpy(palabra_2, temporal);
        }
        printf("las palabras en orden alfabetico: %s, %s", palabra_1, palabra_2);
    } else {
        printf("las palabras en orden son: %s, %s", palabra_1, palabra_2);
    }
}

int main() {
    t_cadena palabra_1 = "alfabeto"; 
    t_cadena palabra_2 = "papalota"; 
    comparar_palabras(palabra_1, palabra_2);
    return 0;
}
