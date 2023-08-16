#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*se desea actualizar el archivo stock evaluando la cantidad de libro vendidos por código de libro del archivo ventas. La actualización se de plasmar en un archivo llamado
stockfin. Para ello se debe tener en cuenta que el código de libro de ventas puede no existir en el archivo stock o que la cantidad vendida pueda ser negativa.
Todos esos errores se deben colcar en un archivo de texto denominado errores.txt y debe figurar el código de operación, el motivo del error y el valor erróneo.*/

#define MAX_REGISTROS 5000

typedef struct {
    int Codigo;
    char Titulo[30];
    int StActual;
} tRegStock;

typedef struct {
    int CodOpe;
    int Codigo;
    int CantVendida;
    char Observaciones[300];
    int CodVendedor;
}tReg_Ventas;

typedef struct {
    int CodVendedor;
    char Nombre[41];
    char Direccion[51]
}tRegVendedor;

void controlarStock(FILE *productosStock, FILE *productosVendidos, FILE *erroresContables, FILE *stockFin){

    productosStock = fopen("stock.dat","r");
    productosVendidos = fopen("ventas.dat","r");
    erroresContables = fopen("errores.txt","w");
    stockFin = fopen("stockfin.dat","wb");
    tRegStock stockDisponible;
    tReg_Ventas ventasRealizadas;

    fread(&stockDisponible, sizeof(tRegStock),1,productosStock);
    fread(&ventasRealizadas, sizeof(tReg_Ventas),1,productosVendidos);

    while(!feof(productosStock) == 1 && !feof(productosVendidos) == 1){
        //compara si el cod de libro en stock coincide con algun cod de libro vendido
        if(stockDisponible.Codigo == ventasRealizadas.Codigo){
            //resta del archivo de stock la cantidad vendida
            stockDisponible.StActual = stockDisponible.StActual - ventasRealizadas.CantVendida;
            //se deberia escribir aca en el nuevo archivo pero no estoy seguro como
            fwrite(&stockDisponible,sizeof(tRegStock),1,stockFin);
        }
        if(ventasRealizadas.CodOpe > 0 ){//se compara si es mayor que cero para saber que si se vendio el libro
            if(ventasRealizadas.Codigo != stockDisponible.Codigo){
                fprintf(erroresContables,"Error en operacion: #%d libro: #%d\n",ventasRealizadas.CodOpe,ventasRealizadas.Codigo);
            }
        }
        if(ventasRealizadas.CantVendida < 0){
            fprintf(erroresContables,"operacion #%d no se llevo a cabo por motivo de ventas %d.\n",ventasRealizadas.CodOpe,ventasRealizadas.CantVendida);
        }
        fread(&stockDisponible, sizeof(tRegStock),1,productosStock);
        fread(&ventasRealizadas, sizeof(tReg_Ventas),1,productosVendidos);
    }
    fclose(productosStock);
    fclose(productosVendidos);
    fclose(erroresContables);
    fclose(stockFin);
}
//Ingresando un código de operación (se supone que el usuario no comete errores al ingresar el numero de código) se pide mostrar los datos del vendedor involucrado
//a lo mucho hay 50 vendedores
void buscarVendedor(FILE *cantVendedores, int codigoRequerido){
    cantVendedores = fopen("vendedores.dat","r");
    tRegVendedor Vendedores;
    fread(&Vendedores, sizeof(tRegVendedor),1,cantVendedores);
    while(!feof(cantVendedores)==1){
        if(Vendedores.CodVendedor == codigoRequerido){
            printf("los datos del vendedor son\n");
            printf("Cod: #%d, Nombre: %s, Direccion %s",Vendedores.CodVendedor,Vendedores.Nombre,Vendedores.Direccion);
        }
        fread(&Vendedores, sizeof(tRegVendedor),1,cantVendedores);
    }
    fclose(cantVendedores);
}

int main(){
    FILE *productosStock, *productosVendidos, *erroresContables, *stockFin, *cantVendedores;
    controlarStock(productosStock, productosVendidos, erroresContables, stockFin);
    buscarVendedor(cantVendedores,315);
    return 0;
}
