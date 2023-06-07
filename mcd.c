#include <stdio.h>

int maximo_comun_divisor(int numero_1, int numero_2){
  int divisor = 2;
  int max = (numero_1 < numero_2) ? numero_2 : numero_1;
  int mcd = 1;
  
  while(divisor <= max){
    if(numero_1 % divisor == 0 && numero_2 % divisor == 0){
      mcd = divisor;
    }
    divisor++;
  }
  
  return mcd;
}

int main(){
  int primer_numero, segundo_numero;
  printf("Ingrese el primer numero: ");
  scanf("%d", &primer_numero);
  printf("Ingrese el segundo numero: ");
  scanf("%d", &segundo_numero);
  
  int resultado = maximo_comun_divisor(primer_numero, segundo_numero);
  printf("El MCD de %d y %d es: %d", primer_numero, segundo_numero, resultado);
  
  return 0;
}
