#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*1) Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición.*/

void asignar_valores(int* lista_numeros, int longitud){
    int v_numeros[250]; 
    int indice_1 = 0;
    
    for (int i = 0; i < longitud; i++){
        if (lista_numeros[i] > 0){
            v_numeros[indice_1] = lista_numeros[i];
            printf("El número agregado: %d, tiene la posición: %d\n", v_numeros[indice_1], indice_1);
            indice_1++;
        }
    }
}

int main(){
    
    int lista_numeros[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int longitud = sizeof(lista_numeros) / sizeof(lista_numeros[0]);
    
    asignar_valores(lista_numeros, longitud);
    
    return 0;
}
