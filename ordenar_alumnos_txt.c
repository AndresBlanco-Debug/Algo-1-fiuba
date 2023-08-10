#include <stdio.h>
#include <string.h>

/*Dado un archivo de apellidos y nombres, generar otro archivo con los mismos datos ordenados alfabéticamente.
Suponer que el archivo de entrada cabe en memoria.*/

#define CANTIDAD_PALABRAS 50
#define MAX_LETRAS_NOMBRE 30

//No hacer una funcion que que lo haga todo, hacer varias funciones que resuelvan un problema

void swap(char *name1, char *name2){
  char aux[MAX_LETRAS_NOMBRE];
  strcpy(aux,name1);
  strcpy(name1,name2);
  strcpy(name2,aux);
}
void ordenamiento_burbujeado(char array_nombres[][MAX_LETRAS_NOMBRE],int cantidad_nombres){
  for(int i = 0; i < cantidad_nombres - 1; i++){
    //el -1 es para evitar el caracter nulo
    for(int j = 0; j < cantidad_nombres - i - 1; j++){
      if(strcmp(array_nombres[j], array_nombres[j + 1]) > 0){
        swap(array_nombres[j], array_nombres[j+1]);
      }
    }
  }
}

void leer_escribir_archivo(FILE *nNombres_Alumnos,FILE *nNombres_Ordenados){
  
  char linea[MAX_LETRAS_NOMBRE];
  int indice = 0;
  char array_nombres[CANTIDAD_PALABRAS][MAX_LETRAS_NOMBRE];
  
  while(fgets(linea, CANTIDAD_PALABRAS, nNombres_Alumnos)){
    strtok(linea,"\n");
    strcpy(array_nombres[indice], linea);
    indice++;
  }
  ordenamiento_burbujeado(array_nombres,indice);
  for(int i = 0; i < indice; i++){
    fprintf(nNombres_Ordenados, "%s\n", array_nombres[i]);
  }
}

int main(){
  FILE *nNombres,*nOrdenados;
  char linea[MAX_LETRAS_NOMBRE];
  int indice = 0;
  nNombres = fopen("nombres_alumnos.txt","r");
  nOrdenados = fopen("nombres_ordenados.txt","w");
  
  if(nNombres == NULL){
    printf("\nError! no se ha podido acceder al archivo");
  }
  if(nOrdenados == NULL){
    printf("\nError! no se ha podido generar el archivo");
    fclose(nNombres);
  }
  leer_escribir_archivo(nNombres,nOrdenados);
  while(fgets(linea,CANTIDAD_PALABRAS,nOrdenados)){
    strtok(linea,"\n");
    printf("los nombres ordenados son %d : %s\n",indice,linea);
  }
  fclose(nNombres);
  fclose(nOrdenados);

  return 0;
}
