#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto. Copiarlo en otro archivo eliminando los espacios superfluos.
O sea eliminar todos los espacios que estan demas*/

void remover_espacios(char *linea){
  
    int longitud = strlen(linea);
    bool espacioPrevio = false; // Para rastrear si el último caracter fue un espacio
    int indiceNuevo = 0; // Índice para la nueva posición en la línea modificada

    for (int i = 0; i < longitud; i++) {
        if (linea[i] != ' ' || !espacioPrevio) {
            linea[indiceNuevo] = linea[i]; // Solo copiar si no es un espacio o si no hay espacios consecutivos
            indiceNuevo++;
        }
        espacioPrevio = (linea[i] == ' ');
    }

    linea[indiceNuevo] = '\0'; // Terminar la cadena correctamente
}


void leer_generar_archivo(FILE *nOraciones, FILE *aLimpio){
  char linea[100];
  while(fgets(linea, sizeof(linea), nOraciones)){
    strtok(linea, "\n");
    remover_espacios(linea);
    fprintf(aLimpio,"%s\n",linea);
  }
}

int main(){
  FILE *nOraciones, *aLimpio;
  nOraciones = fopen("cuento.txt","r");
  aLimpio = fopen("archivo_limpio.txt","w");

  if(nOraciones == NULL){
    printf("\nError! no se ha podido leer el archivo");
  }
  if(aLimpio == NULL){
    printf("\nError! no se pudo generar el archivo!");
    fclose(nOraciones);
  }

  leer_generar_archivo(nOraciones, aLimpio);
  fclose(nOraciones);
  fclose(aLimpio);
}
