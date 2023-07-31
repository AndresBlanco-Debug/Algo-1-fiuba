#include <stdio.h>
#include <string.h>

#define MAX_PALABRAS 20
#define MAX_LONG_STRING 20

void imprimir_array(char array_strings[MAX_PALABRAS][MAX_LONG_STRING], int longitud_array) {
    if (array_strings != NULL) {
        for (int i = 0; i < longitud_array; i++) {
            printf("Las palabras ingresadas son: %s\n", array_strings[i]);
        }
    } else {
        printf("No hay palabras para analizar.\n");
    }
}

void mostrar_palabra_mas_larga(char array_strings[MAX_PALABRAS][MAX_LONG_STRING], int longitud_array) {
    int valor_maximo = 0;
    char palabra_mas_larga[MAX_LONG_STRING];

    for (int i = 0; i < longitud_array; i++) {
        if (strlen(array_strings[i]) > valor_maximo) {
            valor_maximo = strlen(array_strings[i]);
            strcpy(palabra_mas_larga, array_strings[i]);
        }
    }
    printf("La palabra mas larga es: %s\n", palabra_mas_larga);
}

void buscar_palabra_array(char array_strings[MAX_PALABRAS][MAX_LONG_STRING], int longitud_array, char palabra_usuario[]) {
    for (int i = 0; i < longitud_array; i++) {
        if (strcmp(array_strings[i], palabra_usuario) == 0) {
            printf("La palabra '%s' esta en el array.\n", palabra_usuario);
            return; // Importante agregar return para salir del bucle si la palabra es encontrada
        }
    }
    printf("La palabra '%s' NO esta en el array.\n", palabra_usuario);
}

int main() {

    char array_palabras[MAX_PALABRAS][MAX_LONG_STRING];
    int palabras_ingresadas = 0;

    printf("Ingrese hasta 20 palabras.\n");

    while (palabras_ingresadas < MAX_PALABRAS) {
        char palabra[MAX_LONG_STRING];
        printf("Ingrese una palabra: \n");
        scanf("%s", palabra);

        if (strcmp(palabra, "fin") == 0) {
            break;
        }
        strcpy(array_palabras[palabras_ingresadas], palabra);
        palabras_ingresadas++;
    }

    imprimir_array(array_palabras, palabras_ingresadas);
    mostrar_palabra_mas_larga(array_palabras, palabras_ingresadas);

    char palabra_solicitada[MAX_LONG_STRING];
    printf("Ingrese una palabra para buscar: ");
    scanf("%s", palabra_solicitada);
    buscar_palabra_array(array_palabras, palabras_ingresadas, palabra_solicitada);

    return 0;
}
