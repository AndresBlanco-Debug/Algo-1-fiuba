#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos
- Los caracteres no pueden ser todos iguales
Ejemplos:
validar("j2020") devuevle false
validar("2021a") devuevle false
validar("20X21") devuevle false
validar("2220") devuelve true
validar("23445776") devuelve true
validar("089") devuelve false
validar("027845321") devuelve false
validar("02784532") devuelve true
validar("33333") devuelve false*/

typedef char t_cadena[10];

bool clave_valida(t_cadena contrasena){
    bool contrasena_valida = false;
    int contador = 0;
    int longitud_contrasena = strlen(contrasena);
    if(longitud_contrasena > 3 && longitud_contrasena < 9){
        for(int i = 0; i < longitud_contrasena; i++){
            if(isdigit(contrasena[i])){
                contador++;
            }
        }
    }
    if(contador == longitud_contrasena){
        contrasena_valida = true;
    }
    return contrasena_valida;

}

int main(){
    t_cadena string = "2220";
    bool clave = clave_valida(string);
    printf("la clave ingresada es 1 valida, 0 invalida: %d",clave);
    return 0;
}
