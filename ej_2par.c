/*hacer una funcion que reciba como parametro un numero entero y devuelva al moduo invocante los siguientes valores:
 * el mayor digito del numero y la cantidad de veces que este se repite
 * ejemplo: el numero 58381 tiene como maximo 8 y se repite 2 veces*/

void maximo_valor(int numero, int *maximo, int *cantidad_veces){

    int digito;
    *maximo = 0;
    *cantidad_veces = 0;

    while(numero > 0){

        digito = numero % 10;//se saca el ultimo digito del numero
        numero = numero /10;//se actualiza el valor de numero

        if(digito > *maximo){//si el nuevo digito es mayor que el valor en maximo, se asigna a maximo a nuevo valor
            *maximo = digito;
            *cantidad_veces = 1;
        }
        else if(digito == *maximo){
            *cantidad_veces++;
        }
    }
}

int main(){
    int numero = 78549, maximo, cantidad_veces;
    maximo_valor(numero,&maximo,&cantidad_veces);
    printf("numero ingresado: %d\n",numero);
    printf("maximo: %d\n",maximo);
    printf("cant de veces: %d\n",cantidad_veces);
}
