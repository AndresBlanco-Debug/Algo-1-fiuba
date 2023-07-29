#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Escribir una función en C, que reciba una cadena que representa una palabra y
devuelva si la misma es o no un palíndromo.
Una palabra es un palíndromo, si se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- algoritmos (No es palíndromo)
- programas (No es palíndromo)
Evitar realizar ciclos innecesarios.*/

typedef char t_cadena[15];

bool palabra_palindromo(t_cadena palabra){
    bool es_palindromo = true;
    int longitud_palabra = strlen(palabra);
    for(int i = 0, j = longitud_palabra - 1; i < j; i++, j--){
        if(palabra[i] != palabra[j]){
            es_palindromo = false;
        }
    }
    return es_palindromo;
}

int main(){
    t_cadena string = "programas";
    bool palabra_valida = palabra_palindromo(string);
    printf("la palabra ingresada es: %d",palabra_valida);
    return 0;
}
