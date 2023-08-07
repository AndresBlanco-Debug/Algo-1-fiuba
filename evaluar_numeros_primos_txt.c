#include <stdio.h>
#include <stdbool.h>

/*2) Dado un archivo de números enteros, generar otro archivo que contenga aquellos que son primos en el primero.*/


bool numero_primo(int numero){
    bool prime_digit = true;
    if(numero > 1){
        for(int i = 2; i < numero; i++){
            if(numero % i == 0){
                prime_digit = false;
            }
        }
    }
    return prime_digit;
}

void main(){

    FILE *nNumeros,*nRespuestas;
    int numero;

    nNumeros = fopen("numeros.txt","r");
    nRespuestas = fopen("primos_evaluados.txt","w");

    if(nNumeros == NULL){
        printf("\nEl archivo deseado no se pudo abrir");
    }
    if(nRespuestas == NULL){
        printf("\nError al generar archivo!, revise el codigo");
        fclose(nNumeros);
    }
    else{
        while(fscanf(nNumeros, "%d", &numero) == 1){
            bool numero_evaluado = numero_primo(numero);
            if( numero_evaluado == true){
                fprintf(nRespuestas,"%d\n",numero);
            }
        }
    }
    fclose(nNumeros);
    fclose(nRespuestas);
    return;
}
