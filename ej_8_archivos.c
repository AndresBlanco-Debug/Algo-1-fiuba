#include <stdio.h>
#include <string.h>

/*Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto.
 *Calcular la cantidad de monosílabos que hay en el texto, la longitud promedio de las palabras y la cantidad de palabras.*/

int contar_monosilabos(char *oracion){
    int contador = 0;
    int cantidad_monosilabos = 0;
    int longitud_string = strlen(oracion);

    for(int letra = 0; letra < longitud_string; letra++){
        if(oracion[letra] != ' ' && oracion[letra] != '.'){
            if(oracion[letra] == 'a' || oracion[letra] == 'e' || oracion[letra] == 'i' || oracion[letra] == 'o' || oracion[letra] == 'u'){
                contador++;
            }
        }
        if(oracion[letra] == ' '){
            if(contador == 1){
                cantidad_monosilabos++;
                contador = 0;
            }else{
                contador = 0;
            }
        }
    }
    return cantidad_monosilabos;
}
int cantidad_palabras_totales(char *oracion){
    int contador = 0;
    int longitud_oracion = strlen(oracion);
    for(int palabra = 0; palabra < longitud_oracion; palabra++){
        if(oracion[palabra] == ' ' || oracion[palabra] == '.'){
            contador++;
        }
    }
    return contador;
}
int promedio_palabras(char *oracion){
    int cantidad_letras = 0;
    int cantidad_palabras = 0;

    int longitud_oracion = strlen(oracion);
    for(int letra = 0; letra < longitud_oracion; letra++){
        if(oracion[letra] != ' ' && oracion[letra] != '.'){
            cantidad_letras++;
        }
    }
    for(int palabra = 0; palabra < longitud_oracion; palabra++){
        if(oracion[palabra] == ' ' || oracion[palabra] == '.'){
            cantidad_palabras++;
        }
    }
    int promedio = cantidad_letras/cantidad_palabras;
    return promedio;
}

void leer_archivo(FILE *lTexto){
    char linea[50];
    int total_monosilabos = 0;
    int total_palabras = 0;
    int promedio_palabra = 0;
    while(fgets(linea,sizeof(linea),lTexto)){
        strtok(linea,"\n");
        total_monosilabos += contar_monosilabos(linea);
        total_palabras += cantidad_palabras_totales(linea);
        promedio_palabra += promedio_palabras(linea);
    }
    printf("la cantidad de monosilabos es: %d\n",total_monosilabos);
    printf("la cantidad de palabras es: %d\n",total_palabras);
    printf("la longitud promedio de palabras es: %d",promedio_palabra);
}

void main(){
    FILE *lTexto;
    lTexto = fopen("cuento.txt","r");
    if(lTexto == NULL){
        printf("\nError! no se pudo leer el archivo! intente mas tarde");
    }else{
        leer_archivo(lTexto);
    }
    fclose(lTexto);
    return;
}
