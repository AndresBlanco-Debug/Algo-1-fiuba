#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/*5) Cargar un conjunto de números de documento en un vector.
 * No se conoce la cantidad de datos válidos.
 * Informar el número de documento más alto del conjunto y la posición que ocupa.
 * Puede haber repetición, en este caso informar todas las posiciones que ocupa.*/


int* agregar_valores_vector(){

    int* v_numeros = NULL;
    int posicion = 0;
    int numero;
    int valores_ingresados = 0;
    int memoria_inicial = 20;

    v_numeros = (int*) malloc(memoria_inicial*sizeof(int*));
    //se asigna la memoria inicial al array

    do{
        printf("ingrese un numero real, para terminar con el programa ponga 0: ");
        scanf("%d",&numero);
        valores_ingresados++;

        if (valores_ingresados == 0){
            printf("No es posiblr asignar memoria al array, el programa se terminara.");
            break;
        }
        else if( valores_ingresados == 25){
            int nueva_memoria = memoria_inicial * 2;
            int* nuevo_vector = (int*) realloc(v_numeros, nueva_memoria * sizeof(int));
            if(nuevo_vector == NULL){
                printf("imposible asignar memoria");
            }
            v_numeros = nuevo_vector;
            memoria_inicial = nueva_memoria;
        }
        v_numeros[posicion] = numero;
        posicion++;
    }while(numero != 0);

    return v_numeros;
}

void maximo_valor_posicion(int* v_numeros){

    int longitud = 0;
    int i;
    int maximo_valor = v_numeros[0];

    while(v_numeros[longitud] != 0){
        longitud++;
    }
    for(i = 0; i < longitud; i++){
        if(v_numeros[i] > maximo_valor){
            maximo_valor = v_numeros[i];
        }
    }
    printf("el maximo valor del conjunto es: %d\n",maximo_valor);
    for(i = 0; i < longitud; i++){
        if(v_numeros[i] == maximo_valor){
            printf("el maximo valor tiene la posicion: %d\n",i);
        }
    }
}

int main(){
    int* array_numeros = agregar_valores_vector();
    maximo_valor_posicion(array_numeros);
}
