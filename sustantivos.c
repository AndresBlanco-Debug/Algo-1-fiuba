EL PROGRAMA NECESITA AJUSTES
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Escribir una función que recibirá por parámetro, una palabra, que representa un
sustantivo en singular.
La función deberá devolver, el plural de dicho sustantivo, aplicando las
siguientes reglas:
a. Agregar una “s” al final, si la palabra termina en vocal sin acento.
b. Agregar una “s” al final, si la palabra termina con una é (acentuada).
c. Si la palabra termina en “z”, la reemplazamos por “ces”.
d. Agregamos “es” al final, si la palabra termina en una consonante (a excepción
de la “s”, la “z”, y la “x”), ó si la palabra termina con las vocales acentuadas: á,
í, ó, ú.
e. Si el sustantivo termina en “s” ó “x”, entonces el plural es igual al singular,
por lo tanto la función deberá devolver lo mismo que recibió.

Para cada uno de los siguientes ejercicios, deberás escribir un programa compuesto
por una o más funciones. Recordá que lo adecuado es que una función realice sólo
una tarea, por eso, antes de ponerte a programar cada una de las soluciones de los
ejercicios, diseña la solución indicando cuáles serán las funciones que escribirás y
compondrán tu programa.*/

typedef char t_cadena[25];

void agregar_palabra_sin_acento(t_cadena palabra){

    int longitud_palabra = strlen(palabra);
    char final_cadena[] = "s";

    //no hay necesidad de hacer un ciclo para recorrer la palabra, basta con acceder a la ultima letra del array
    if(palabra[longitud_palabra - 1] == 'a' || palabra[longitud_palabra - 1] == 'e' || palabra[longitud_palabra - 1] == 'i'
    || palabra[longitud_palabra - 1] == 'o' || palabra[longitud_palabra - 1] == 'u'){
        strcat(palabra,final_cadena);
        palabra[longitud_palabra + 1] = '\0';
    }
}

void agregar_palabra_punto_b(t_cadena palabra){
    int longitud_palabra = strlen(palabra);
    char final_cadena[] = "s";
    if(palabra[longitud_palabra - 1] == "é"){
        strcat(palabra,final_cadena);
    }
}

void remplazar_punto_c(t_cadena palabra){
    int longitud_palabra = strlen(palabra);
    char final_cadena[] = "ces";
    if(palabra[longitud_palabra - 1] == 'z'){
        strcat(palabra,final_cadena);
    }
}

void remplazar_punto_d(t_cadena palabra){
    int longitud_palabra = strlen(palabra);
    char final_cadena[] = "es";
    if(palabra[longitud_palabra - 1] != 'x' || palabra[longitud_palabra] != 'z' || palabra[longitud_palabra - 1] != 's'
    || palabra[longitud_palabra - 1] == "á" || palabra[longitud_palabra - 1] == "í" || palabra[longitud_palabra - 1] == "ó"
    || palabra[longitud_palabra - 1] == "ú"){
        strcat(palabra,final_cadena);
    }
}

void remplazar_punto_e(t_cadena palabra){
    int longitud_cadena = strlen(palabra);
    if(palabra[longitud_cadena - 1] == 'x' || palabra[longitud_cadena - 1] == 's'){

    }
}

int main() {
    t_cadena palabra;

    // Lectura del sustantivo en singular
    printf("Ingrese un sustantivo en singular: ");
    scanf("%s", palabra);

    // Aplicar las reglas para obtener el plural
    agregar_palabra_sin_acento(palabra);
    agregar_palabra_punto_b(palabra);
    remplazar_punto_c(palabra);
    remplazar_punto_d(palabra);
    remplazar_punto_e(palabra);

    // Imprimir el plural obtenido
    printf("El plural es: %s\n", palabra);

    return 0;
}
