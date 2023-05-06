#include <stdio.h>
/*Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n.*/

long sumatoriaNumeros(int numero){
  long suma = 0;
  int contador = 0;
  int varAux = numero;
  
  while(contador <= numero){
    suma = suma + varAux;
    varAux -- ;
    contador ++ ;
  }
  return suma;
}

int main(){
  int numero;
  printf("Ponga un numero natural: ");
  scanf("%d",&numero);
  int suma = sumatoriaNumeros(numero);
  printf("El total de la sumatoria es %d: ",suma);
}   
