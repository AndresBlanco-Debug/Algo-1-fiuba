/*Escribir un programa que solicite el ingreso de dos números, y luego informe los
números primos que hay entre esos dos números.
Se debe validar que los números ingresados sean enteros y además que el primer
número sea menor o igual que el segundo.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esPrimo(int numero){
  int divisor;
  bool validarPrimo = true;

  for (divisor = 2; divisor < numero; divisor++){
    if (numero % divisor == 0){
      validarPrimo = false;
    }
  }
  return validarPrimo;
}

int agregarValoresArray(int numero_1, int numero_2){
  
  int contador;
  int cadena[100];
  int max = (numero_1 < numero_2) ? numero_2 : numero_1;
  int min = (numero_1 < numero_2) ? numero_1 : numero_2;

  for (contador = 0; min < max; min++, contador++){
    cadena[contador] = min;
  }
  for (int i = 0; i < (max-numero_1); i++){
    printf("los valores del array son: %d, \n",cadena[i]);
  }
  for (int index = 0; index < (max - numero_1); index++){
    if(esPrimo(cadena[index]) == false){
      printf("El numero %d, no es primo\n",cadena[index]);
    }
    else{
      printf("El numero %d, es primo\n",cadena[index]);
    }
  }
  return 0;
}

int main(){
  int numero_1;
  int numero_2;
  printf("ingrese el primer numero: ");
  scanf("%d",&numero_1);
  printf("ingrese el segundo numero: ");
  scanf("%d",&numero_2);
  int resolucion = agregarValoresArray(numero_1, numero_2);
  printf("%d",resolucion);
  return 0;
}
