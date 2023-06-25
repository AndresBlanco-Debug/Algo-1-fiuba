#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/*3) Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y x un real, almacenar x en la posición i de un vector. El listado no se ingresa
ordenado por posición. Informar la cantidad de números y el contenido del
vector indicando la posición ocupada por cada número a partir de la primera
posición. */


typedef struct {
    int posicion;
    double valor;
} v_numeros;

void almacenar_valores(){
    int cantidad_valores;

    printf("ingrese la cantidad total de valores: ");
    scanf("%d",&cantidad_valores);

    v_numeros* array = (v_numeros*)malloc(cantidad_valores * sizeof(v_numeros));
    if(array == NULL){
        printf("valor invalido, no se puede asignar memoria\n");
    }
    for (int i = 0; i < cantidad_valores; i++){
        printf("ingrese la posicion: ");
        scanf("%d",&array[i].posicion);
        printf("ingrese el valor: ");
        scanf("%lf",&array[i].valor);
    }
    printf("la cantidad total de elementos es: %d\n",cantidad_valores);
    printf("el contenido del vector es:\n");
    for (int i = 0; i < cantidad_valores; i++){
        printf("posicion %d: %.2lf\n", array[i].posicion, array[i].valor);
    }
    free(array);
}
int main(){
    almacenar_valores();
    return 0;
}
