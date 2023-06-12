/*Escribir un programa que solicite el ingreso de valores, que representarán una
cantidad de segundos. El programa deberá informar al usuario, el equivalente en
días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void validarDato(int segundos){
  int minutos = segundos / 60;
  int horas = minutos / 60;
  int dias = horas / 24;

  printf("segundos: %d\n",segundos);
  printf("minutos: %d\n",minutos);
  printf("horas: %d\n",horas);
  printf("dias: %d\n",dias);

}

int main(){
  int tiempo;
  do{
    printf("Ingrese la cantidad en segundos: \n");
    if(scanf("%d",&tiempo) != 1){
      printf("valor invalido, por favor ingrese otro valor");
      scanf("%*s"); 
      continue;
    };
    if (tiempo == 0){
      printf("Tiempo invalido");
    }
    validarDato(tiempo);
  }
    while(tiempo > 0);
  return 0;
}
