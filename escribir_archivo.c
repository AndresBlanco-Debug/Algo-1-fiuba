#include <stdio.h>

//programa que escribe archivo.dat (binario) desde 0

typedef struct {
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void cargar_datos(FILE *arProductos){
    t_regProducto rProducto;

    printf("Ingrese el codigo del articulo: ");
    scanf("%d",&rProducto.codigo);
    fflush(stdin);

    while(rProducto.codigo != 0){
        printf("Descripcion: ");
        scanf("%30[^\n]s",rProducto.descripcion);
        fflush(stdin);

        printf("Cantidad en stock: ");
        scanf("%f",&rProducto.cantidad);
        fflush(stdin);

        fwrite(&rProducto,sizeof(rProducto),1,arProductos);

        printf("\nCodigo de articulo: ");
        scanf("%d",&rProducto.codigo);
        fflush(stdin);

    }
}

int main(){
    FILE *arProductos;
    arProductos = fopen("productos.dat","wb");
    if(arProductos == NULL){
        printf("\nNo se puede abrir el archivo!\n");
    }
    else{
        cargar_datos(arProductos);
        fclose(arProductos);
    }
    return 0;
}
