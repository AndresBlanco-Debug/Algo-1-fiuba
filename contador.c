#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define PRECIO_POR_3_CARACTERES 10
#define PRECIO_POR_FRACCION 8

int contar_palabras(const char* texto) {
    int contador = 0;
    int indice = 0;
    bool palabra = false;
    int longitud = strlen(texto);

    while (indice < longitud) {
        if (isalnum(texto[indice])) {
            if (!palabra) {
                palabra = true;
                contador++;
            }
        } else {
            palabra = false;
        }
        indice++;
    }

    return contador;
}

int precio_por_envio(const char* texto) {
    int precio = 0;
    int indice = 0;
    bool dentroPalabra = false;
    int contador = 0;
    int longitud = strlen(texto);

    while (indice < longitud) {
        if (isalnum(texto[indice])) {
            if (!dentroPalabra) {
                dentroPalabra = true;
                contador = 0;
            }
            contador++;
        } else {
            if (dentroPalabra) {
                dentroPalabra = false;
                if (contador >= 3) {
                    precio += PRECIO_POR_3_CARACTERES;
                } else {
                    precio += PRECIO_POR_FRACCION;
                }
            }
        }
        indice++;
    }
    return precio;
}

int main() {
    char texto[256];

    printf("Ingrese el texto del telegrama: ");
    fgets(texto, sizeof(texto), stdin);

    int palabras = contar_palabras(texto);
    int importe = precio_por_envio(texto);

    printf("Cantidad de palabras: %d\n", palabras);
    printf("Importe a abonar: $%d\n", importe);

    return 0;
}
