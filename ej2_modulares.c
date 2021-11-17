#include <stdio.h>
/*Escribir un programa que solicite el ingreso de una serie de números.
Por cada número ingresado se deberá informar si el mismo es ó no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo; de lo contrario,
se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente.
El ingreso de números, termina cuando en lugar de un número, el usuario ingresa
“FIN”.
*/


int main(){

  int numero;
  int ninv = 0;
  int aux = numero;

  scanf("por favir ingrese un numero positivo: %d", &numero);

  while(numero > 0){
     ninv = numero%10 + ninv *10;
     numero = numero / 10;
    }
  if(ninv==aux){
    printf("el numero es capicuo");
  }
  else{
    printf("el numero no es capicuo");
  }



  return 0;

}
