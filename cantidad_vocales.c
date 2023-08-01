#include <stdio.h>


/*Escribir un programa modular en C, que solicite el ingreso de 1 oración, de no
más de 100 caracteres.
Luego informar la cantidad de vocales minúsculas, no acentuadas, que hay en la
oración.*/

#define MAX_LEN_ORACION 101
typedef char multi_string[MAX_LEN_ORACION];

void contar_caracteres_especiales(multi_string oracion){
    int contador = 0;
    for(int i = 0; oracion[i] != '\0'; i++){
        if(oracion[i] == 'a' || oracion[i] == 'e' || oracion[i] == 'i' || oracion[i] == 'o' || oracion[i] == 'u'){
            contador++;
        }
    }
    printf("la cantidad de vocales no acentuadas es : %d",contador);
}

int main(){
    multi_string oracion= "hola tenemos un problema";
    contar_caracteres_especiales(oracion);
    return 0;
}
