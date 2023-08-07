#include <stdio.h>

/*1) Dado un archivo de números enteros mayores o iguales que 0, generar otro archivo que almacene los factoriales de cada número del registro correspondiente del archivo de entrada.*/


unsigned long long calcular_factorial(int numero) {
  long long factorial = 1;
  
  if (numero == 0 || numero == 1) {
    factorial = 1;
  } else if (numero > 1) {
    for (int i = 1; i <= numero; i++) {
      factorial = factorial * i;
    }
  }
  
  return factorial;
}

void main(){
  FILE *nNumeros, *rFactoriales;
  int numero;
  
  nNumeros = fopen("numeros.txt","r");
  rFactoriales = fopen("respuestas.txt","w");

  if(nNumeros == NULL){
    printf("\nel archivo no se ha podido abrir!");
  }
  if(rFactoriales == NULL){
    printf("\nel archivo de respuestas no se ha posido generar");
    fclose(nNumeros);
  }
  else{
    while (fscanf(nNumeros, "%d", &numero) == 1){
      unsigned long long resp = calcular_factorial(numero);
      fprintf(rFactoriales, "%d: %llu\n",numero,resp);
    }
    
  }
  fclose(nNumeros);
  fclose(rFactoriales);

  return;
  
}
