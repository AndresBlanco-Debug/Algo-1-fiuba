#include <stdio.h>
#include <stdbool.h>

/*Dados dos archivos de números enteros de 5 dígitos ordenados en forma creciente,
 * generar un archivo que contenga todos los números, ordenado de igual forma. No hay números repetidos.*/


void ordenamiento_por_burbujeo(int array_numeros[],int longitud_archivo){

    bool ordenado;
    do{
        ordenado = true;
        for(int i = 0; i < longitud_archivo; i++){
            if(array_numeros[i] > array_numeros[i + 1]){
                int aux = array_numeros[i];
                array_numeros[i] = array_numeros[i+1];
                array_numeros[i + 1] = aux;
                ordenado = false;
            }
        }
    } while(ordenado == false);
}

int main(){
    FILE *nNumeros_1,*nNumeros_2,*nRespuestas;

    nNumeros_1 = fopen("numeros_ordenar.txt","r");
    nNumeros_2 = fopen("numero_ordenar_2.txt","r");
    nRespuestas = fopen("numeros_ordenados.txt","w");

    if(nNumeros_1 == NULL){
        printf("\nHubo un error al leer al archivo!");
    }
    if(nNumeros_2 == NULL){
        printf("\nError! no se pudo leer el archivo!");
        fclose(nNumeros_1);
    }
    if(nRespuestas == NULL){
        printf("\nEl archivo final no se pudo abrir!");
        fclose(nNumeros_1);
        fclose(nNumeros_2);
    }else{
        int numeros[200];
        int total_numeros = 0;

        while(fscanf(nNumeros_1,"%d",&numeros[total_numeros]) != EOF){
            total_numeros++;
        }
        while(fscanf(nNumeros_2,"%d",&numeros[total_numeros]) != EOF){
            total_numeros++;
        }
        ordenamiento_por_burbujeo(numeros,total_numeros);

        for(int i = 0; i < total_numeros; i++){
            fprintf(nRespuestas,"%d\n",numeros[i]);
        }
    }
    fclose(nNumeros_1);
    fclose(nNumeros_2);
    fclose(nRespuestas);

    return 0;
}
