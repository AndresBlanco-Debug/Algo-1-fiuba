/*Escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas.
Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.
Tener en cuenta que el usuario puede ingresar valores negativos.*/

int productoPorSumas(int numero_1, int numero_2){
  int contador = 0;
  int resultado = 0;
  while (contador < abs(numero_2)){
    resultado = resultado + numero_1;
    contador ++;
  }
  return resultado; 
}

int main(){
  int numero1,numero2;
  printf("ponga el primer numero: ");
  scanf("%d",&numero1);
  printf("ponga el segundo numero: ");
  scanf("%d",&numero2);
  int valor = productoPorSumas(numero1,numero2);
  printf("el resultado es: %d",valor);
  return 0;
}
