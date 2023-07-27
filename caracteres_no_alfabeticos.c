#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Escribir una función que reciba como parámetro una cadena de caracteres y
devuelva la cantidad de caracteres no alfabéticos que hay en la cadena.
No tener en cuenta la ñ, ni las vocales acentuadas.*/

void contar_caracteres_no_alfabeticos(char cadena[]){
    int contador = 0;
    int longitud_cadena = strlen(cadena);
    for(int i = 0; i < longitud_cadena; i++){
        if(!isalpha((cadena[i]))){
            //cuenta los espacios y el caracter nulo
            contador++;
        }
    }
    printf("la cantidad de caracteres no alfabeticos es: %d",contador);
}

int main(){
    char cadena[] = "";
    printf("ingrese la cadena: ");
    fgets(cadena,15,stdin);
    fflush(stdin);
    contar_caracteres_no_alfabeticos(cadena);
    return 0;
}
