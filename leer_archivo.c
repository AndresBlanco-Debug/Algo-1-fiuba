#include <stdio.h>

typedef struct {
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void leer_datos(FILE *arProductos){

    t_regProducto rProducto;
    fread(&rProducto,sizeof(rProducto),1,arProductos);
    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while(!feof(arProductos)){
        printf("\n %d \t%-30s %f.2f",rProducto.codigo,rProducto.descripcion,rProducto.cantidad);
        fread(&rProducto, sizeof(rProducto),1,arProductos);
    }
}

int main(){

    FILE *arProductos;

    arProductos = fopen("productos.dat","rb");
    if(arProductos == NULL){
        printf("\nNo se puede abrir el archivo!\n");
    }
    else{
        leer_datos(arProductos);
        fclose(arProductos);
    }
    return 0;
}
