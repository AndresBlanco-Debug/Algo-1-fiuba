#include <stdbool.h>
#include <stdio.h>
/*Escribir una función que reciba un mes y un año; y devuelva la cantidad de
días del mes, considerando los años bisiestos. Tenga en cuenta que un año
bisiesto es aquel divisible por 4, salvo que sea divisible por 100, en cuyo caso
también debe ser divisible por 400. 2.*/

bool verificar_ano(int ano) {
  return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
}

int dias_del_mes(int mes, int year) {
  int dias;
  if (mes != 2 && mes < 8 && mes % 2 == 0) {
    dias = 30;
  } else if (mes != 2 && mes > 8 && mes < 13 && mes % 2 == 0) {
    dias = 31;
  } else if (mes == 2) {
    if (verificar_ano(year) == true) {
      dias = 29;
    } else {
      dias = 28;
    }
  } else {
    dias = 31;
  }
  return dias;
}

int main() {
  int mes, ano;
  printf("Por favor ingrese un mes en numeros: ");
  scanf("%d", &mes);
  printf("Por favor ingrese un ano en valores numericos: ");
  scanf("%d", &ano);
  int dias = dias_del_mes(mes, ano);
  printf("El mes ingresado tiene %d dias", dias);
}
