/*Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo; de lo contrario,
se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validarCapicua(int numero){
    
    char cadena[20];
    bool valido;
    sprintf(cadena, "%d", numero);
    int index_1, index_2;
    int longitud = strlen(cadena);
    

    for (index_1 = 0, index_2 = longitud - 1; index_1 < index_2; index_1 ++, index_2 --){
        if (cadena[index_1] != cadena[index_2]){
            index_1 = longitud;
            valido = false;
        }
      else{ valido = true; }
    }
    
    return valido;
}


int main(){

  int numero;
  char cadena[20];
  char respuesta[] = "FIN";

  do{
    printf("por favor ingrese un numero natural: ");
    scanf("%d",&numero);

    if (validarCapicua(numero)){
      printf("El numero ingresado es capicua :D\n");
    }
    else{
      printf("El numero ingresado no es capicua");
    }
    printf("Desea seguir ingresando numeros:?(Si desea terminar el programa ingrese 'FIN') ");
    scanf("%s",cadena);
  }
    while(strcmp(cadena, respuesta) != 0);

  return 0;
}
