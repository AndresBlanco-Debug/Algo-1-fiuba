#include <stdio.h>
/*Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado.*/

int calcular_factorial(int numero){
  int acumulador;
  int factorial = 1;
  if (numero >=0 && (numero == 0 || numero == 1)){
    factorial = 1;
  }
  else if(numero > 1){
    for(acumulador = 1; acumulador <= numero; acumulador++)
      factorial = factorial * acumulador;
  }
  else{
    factorial = 0;
  }
  return factorial;
}

int main(){
  int numero;
  printf("Ingrese un numero natural: ");
  scanf("%d",&numero);
  int factorial = calcular_factorial(numero);
  printf("el factorial de %d es %d",numero,factorial);
  
}
