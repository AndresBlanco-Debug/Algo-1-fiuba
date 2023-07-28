#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*Escribir una función para validar una nueva clave de acceso.
La función deberá recibir una cadena de caracteres, que contendrá la clave
candidata, que ya fue ingresada previamente por el usuario.
Devolverá true o false, dependiendo de si cumple o no, con las siguientes
condiciones:
- La clave debe estar formada únicamente por, entre 6 y 12 caracteres
numéricos
- La cantidad de dígitos pares debe ser mayor a la de los impares.
A los sumo debe recorrer una vez la cadena.
Evite realizar ciclos innecesarios.
Compruebe el correcto funcionamiento, incluyendo los siguientes casos de
prueba:
validar("j20893") devuevle false
validar("20893a") devuevle false
validar("208X930") devuevle false
validar("20201") devuelve false
validar("23445776") devuelve false
validar("089010") devuelve true
validar("02784532132567") devuelve false
validar("027845320011") devuelve true*/

typedef char t_cadena[15];

bool  numero_par(char numero){
    bool numero_par = false;
    if(numero % 2 == 0){
        numero_par = true;
    }
    return numero_par;
}

bool validar_contrasena(t_cadena clave){

    bool clave_valida = false;
    int cantidad_pares = 0,cantidad_impares = 0;
    int longitud_clave = strlen(clave);

    if(longitud_clave > 5 && longitud_clave < 13){
        for(int i = 0; i < longitud_clave; i++){
            if(isdigit(clave[i]) && clave[i] != '0' && numero_par(clave[i]) == true){
                cantidad_pares++;
            }
            if(isdigit(clave[i]) && numero_par(clave[i]) == false){
                cantidad_impares++;
            }
        }
        if(cantidad_impares < cantidad_pares){
            clave_valida = true;
        }
    }
    return clave_valida;
}

int main(){
    t_cadena string ="j20893";
    bool clave_valida = validar_contrasena(string);
    printf("la clave ingresada es %d",clave_valida);
    return 0;
}
