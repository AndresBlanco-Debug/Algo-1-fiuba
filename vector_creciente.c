#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

/*6) Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente y el segundo ordenado descendente,
 * crear un nuevo vector c de n + m elementos intercalando los elementos de a y b de modo que c quede ordenado ascendente.*/

int* agregar_elementos(int vector_a[], int longitud_a, int vector_b[], int longitud_b, int longitud_total) {
    int* v_numeros = NULL;
    int memoria_inicial = 20;
    int contador_elementos = 0;
    int i = 0, j = 1, k = 0;

    v_numeros = (int*) malloc(memoria_inicial * sizeof(int));

    do {
        if (longitud_total == 0) {
            printf("No se ingresaron elementos validos, no se ha podido asignar memoria, se cerrara el programa.");
            break;
        } else if (contador_elementos >= memoria_inicial) {
            int nueva_memoria = memoria_inicial * 2;
            int* nuevo_vector = (int*) realloc(v_numeros, nueva_memoria * sizeof(int));

            v_numeros = nuevo_vector;
            memoria_inicial = nueva_memoria;
        }

        v_numeros[i] = vector_a[k];
        v_numeros[j] = vector_b[k];
        contador_elementos += 2;
        i += 2;
        j += 2;
        k++;
    } while (contador_elementos < longitud_total);

    return v_numeros;
}

void ordenar_vector(int* v_numeros, int longitud_array) {
    int posicion_1;
    int ordenado;

    do{
        ordenado = 1;
        for (posicion_1 = 0; posicion_1 < longitud_array; posicion_1++) {
            if (v_numeros[posicion_1] > v_numeros[posicion_1 + 1]) {
                int aux = v_numeros[posicion_1];
                v_numeros[posicion_1] = v_numeros[posicion_1 + 1];
                v_numeros[posicion_1 + 1] = aux;
                ordenado = 0;
            }
        }
    } while (ordenado == 0);
    printf("Los elementos del array ordenados de menor a mayor son: ");
    for (int i = 0; i < longitud_array; i++) {
        printf("%d ", v_numeros[i]);
    }
    printf("\n");
}

int main() {
    int arreglo_a[] = {1, 7, 2, 66, 9};
    int arreglo_b[] = {45, 3, 9, 8};
    int longitud_a = sizeof(arreglo_a) / sizeof(arreglo_a[0]);
    int longitud_b = sizeof(arreglo_b) / sizeof(arreglo_b[0]);
    int longitud_total = longitud_a + longitud_b;

    int* escribir_vector = agregar_elementos(arreglo_a, longitud_a, arreglo_b, longitud_b, longitud_total);
    ordenar_vector(escribir_vector, longitud_total);

    free(escribir_vector);

    return 0;
}
