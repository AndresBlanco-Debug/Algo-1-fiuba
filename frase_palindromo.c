#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Escribir una función en C, que reciba una cadena que representa una palabra o
una frase y devuelva si la misma es o no un palíndromo.
Un palíndromo, es una palabra o frase que se lee igual en ambos sentidos.
Probar la función con los siguientes casos de prueba:
- anilina (Es palíndromo)
- ojo (Es palíndromo)
- radar (Es palíndromo)
- reconocer (Es palíndromo)
- amar a roma (Es palíndromo)
- ana lava lana (Es palíndromo)
- a ti no, bonita (Es palíndromo)
- algoritmos y programas (No es palíndromo)
- lenguaje C (No es palíndromo)
Evitar realizar ciclos innecesarios.*/

typedef char t_cadena[25];

bool palabra_palindromo(t_cadena palabra){
    bool es_palindromo = true;
    int longitud_palabra = strlen(palabra);
    for(int i = 0, j = longitud_palabra - 1; i < j; i++, j--){
        if(palabra[i] != palabra[j] && palabra[i] != ' ' && palabra[j] != ' '){
            es_palindromo = false;
        }
    }
    return es_palindromo;
}

int main(){
    t_cadena string = "algoritmos y programas";
    bool palabra_valida = palabra_palindromo(string);
    printf("la palabra ingresada es: %d",palabra_valida);
    return 0;
}
