#include <stdio.h>
#include <string.h>


/*Escribir una función en C que reciba como primer parámetro, una cadena de tipo
t_cadena, y devuelva como segundo parámetro, la misma cadena pero invertida,
sin considerar los blancos.
Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas
posiciones potenciales a ser utilizadas pero que podrían contener caracteres
inciertos.
Recorrer la cadena a lo sumo una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes casos y las impresiones para comprobar que devuelven lo correcto.
Casos:
invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena(" ", cad_invertida) ==> cad_invertida: ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida: "somosoNsomoS"*/

typedef char t_cadena[100];

void invertir_cadena(t_cadena string, t_cadena *cadena_invertida){
    int len = strlen(string);
    int index_invertido = 0;
    for(int i = len-1; i >= 0; i--){
        if(string[i] != ' ' && string[i] != '\n' && string[i] != '\t'){
            (*cadena_invertida)[index_invertido] = string[i];
            index_invertido++;
        }
    }
    (*cadena_invertida)[index_invertido] = '\0';
}

int main() {
    t_cadena cadena_original1 = "Hola, me llamo Ana.";
    t_cadena cadena_original2 = "234561";
    t_cadena cadena_original3 = " ";
    t_cadena cadena_original4 = "Somos o No somos";

    t_cadena cadena_invertida1, cadena_invertida2, cadena_invertida3, cadena_invertida4;

    invertir_cadena(cadena_original1, &cadena_invertida1);
    invertir_cadena(cadena_original2, &cadena_invertida2);
    invertir_cadena(cadena_original3, &cadena_invertida3);
    invertir_cadena(cadena_original4, &cadena_invertida4);

    printf("invertir_cadena(\"%s\") ==> cad_invertida: \"%s\"\n", cadena_original1, cadena_invertida1);
    printf("invertir_cadena(\"%s\") ==> cad_invertida: \"%s\"\n", cadena_original2, cadena_invertida2);
    printf("invertir_cadena(\"%s\") ==> cad_invertida: \"%s\"\n", cadena_original3, cadena_invertida3);
    printf("invertir_cadena(\"%s\") ==> cad_invertida: \"%s\"\n", cadena_original4, cadena_invertida4);

    return 0;
}
