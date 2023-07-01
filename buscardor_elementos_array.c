#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/*7) Dado un vector a de longitud n y un elemento p del mismo tipo que los elementos del vector,
 * buscar p en el vector a y devolver la posición que ocupa en caso de encontrarlo o una señal en caso contrario. Suponer que no hay repeticiones.*/

void buscador(int vector_a[],int longitud_vector,int elemento){
    bool valor = false;
    for(int i = 0; i < longitud_vector; i++){
        if (vector_a[i] == elemento){
            printf("el emenento %d esta en la posicion en: %d",vector_a[i],i);
            valor = true;
        }
    }
    if(valor == false){
        printf("el elemento no esta en el vector");
    }
}

int main(){
    int vector[] = {1,8,9,3,7,1,0,3};
    int numero;
    int longitud= sizeof(vector) / sizeof(vector[0]);


    printf("ingrese el elemeto que quiere buscar: ");
    scanf("%d",&numero);

    buscador(vector,longitud,numero);
    return 0;
}
