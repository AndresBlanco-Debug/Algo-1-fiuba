#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/*funcion que recibe un vector como parametro y su maximo logico
 *funcion debe regresar a lo sumo los primeros 5 valores pares del vector
 * y el maximo logico del vector*/

void analizar_vector(int vector_numerico[], int *maximo_logico, int longitud, int v_num_pares[]){

    *maximo_logico = 0;
    int cantidad_pares = 0;

    for (int i = 0; i < longitud && cantidad_pares < 5; i++){
        if(vector_numerico[i] % 2 == 0){
            v_num_pares[cantidad_pares] = vector_numerico[i];
            cantidad_pares++;
        }
    }
    for(int i = 0; i < cantidad_pares; i++){
        printf("los elementos del nuevo array son: %d\n",v_num_pares[i]);
    }
    for(int i = 0; i < cantidad_pares; i++){
        if(v_num_pares[i] > *maximo_logico){
            *maximo_logico = v_num_pares[i];
        }
    }
    printf("el maximo logico es : %d",*maximo_logico);
}

int main(){
    int vector[] = {16,-24,8,9,3,7,10,22,14,8,32};
    int maximo_logico;
    int longitud = sizeof (vector) / sizeof (vector[0]);
    int pares[5];

    analizar_vector(vector,&maximo_logico,longitud,pares);

}
