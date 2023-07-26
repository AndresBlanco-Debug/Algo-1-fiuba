#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de dígitos numéricos que hay en la cadena.*/

void contar_numeros(char cadena[]){
    int contador = 0;
    int longitud_array = strlen(cadena);
    for(int i = 0; i < longitud_array; i++){
        if(isdigit(cadena[i])){
            contador++;
        }
    }
    printf("cantidad de numeros en el string: %d", contador);

}

int main(){
    char cadena[] = "";
    printf("ingrese el texto: ");
    fgets(cadena,20,stdin);
    fflush(stdin);
    contar_numeros(cadena);
    return 0;
}


