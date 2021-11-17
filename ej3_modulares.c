#include <stdio.h>

/*Escribir un programa que solicite el ingreso de valores, que representarán una
cantidad de segundos. El programa deberá informar al usuario, el equivalente en
días, horas, minutos y segundos.
Se debe validar que el valor ingresado sea entero y positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
El ingreso de valores finaliza cuando el usuario ingrese como valor, 0.
*/


int main(){

  int segundos;
  float minutos;
  float horas;
  float dias;

  printf("por favor ingrese un numero mayor a cero: ");
  scanf("%d",&segundos);

  if(segundos > 0){
    minutos = segundos/60;
    horas = minutos/60;
    dias = horas/24;
  }
  printf("los segundos son: %d\n",segundos);
  printf("los minutos son: %e\n",minutos);
  printf("las horas son: %e\n",horas);  
  printf("los dias son: %e\n",dias);

  if(segundos<0){
    printf("por favor ingrese una cantida valida");
  }

  return 0;

}
