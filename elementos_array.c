#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CARACTERES 100
typedef int array[MAX_CARACTERES];

int main() {
    array v_numeros;
    int indice = 0;
    int numero, i;
    int longitud_array = sizeof(v_numeros) / sizeof(v_numeros[0]);
    int sumatoria = 0;

    do {
        printf("Ingrese un numero real diferente de 0: ");
        scanf("%d", &numero);

        if (numero == 0) {
            printf("Numero invalido, programa terminado.\n");
            break; // Salir del bucle
        } else {
            v_numeros[indice] = numero;
            sumatoria++;
        }
        indice++;
    } while (indice < longitud_array);

    for (i = 0; i < sumatoria; i++) {
        printf("El elemento: %d, tiene la posicion: %d\n", v_numeros[i], i);
    }
    printf("La cantidad total de elementos del vector es: %d\n", sumatoria);

    return 0;
}
