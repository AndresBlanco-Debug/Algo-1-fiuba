#include <stdio.h>

/*3) Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres correspondientes según el código ASCII.*/



void generar_palabra(int numero){
    if(numero >= 0 && numero <256){
        printf("El caracter correspondiente al codigo ASCII %d es: %c\n", numero, numero);
    }
}

void main(){
    FILE *nCaracteres;
    int numero;
    nCaracteres = fopen("numeros_palabras.txt","r");

    if(nCaracteres == NULL){
        printf("\nel archivo no se puede abrir!");
    }else{
        while(fscanf(nCaracteres, "%d",&numero) == 1){
            if(numero >= 0 && numero <256){
                printf("Numero %d es el caracter %c\n",numero,(char)numero);
            }
            else{
                printf("El caracter no esta definido");
            }
        }
    }
    fclose(nCaracteres);
    return;
}
