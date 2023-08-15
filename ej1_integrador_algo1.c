#include <stdio.h>

/*UNA EMPRESA DENOMINADA MULTINACIONAL POSEE UN ARCHIVO DENOMINADO SucTop.dat CON LA ESTRUCTURA MOSTRADA ABAJO.
EL ARCHIVO ESTA ORDENADO ASCENDENTEMENTE POR CODIGO
AL FINAL DE CADA DIA SE DEBE PROCESAR JUNTTO CON OTRO ARCHIVO, DENOMINADO novedades.dat. ESTE ARCHIVO CONTIENE
LAS SUCURSALES NUEVAS, TAMBIEN ESTA ORDENADO ASCENDENTEMENTE POR CODIGO Y TIENE LA MISMA ESTRUCTURA
SE PIDE DESARROLLAR UNA FUNCION EN C PARA REALIZAR DICHO PROCESAMIENTO. COMO RESULTADO DE ESTE SE DEBE GENERAR
EL ARCHIVO SucArgGra.dat (REGISTROS TRegSuc) SUCURSALES ARGENTINAS GRANDES
EL ARCHIVO SucArgGra.dat DEBE QUEDAR ORDENADO ASCENDENTEMENTE POR CODIGO Y CONTENER SOLAMENTE LAS SUCURSALES
QUE TENGAS MAS DE 100 EMPLEADOS
ASUMA QUE NO HAY CODIGOS REPETIDOS NI ERRORES DE NINGUN TIPO*/

typedef struct{
int codigo;
char pais[20];
char ciudad[20];
int cantidadEmpleados;
}TRegSuc;

typedef TRegSuc sucursales[250];

void adjuntarSucursal(FILE *nSucursales, FILE *nNovedades, FILE *aFinal){

  TRegSuc sucursal;
  TRegSuc aux;
  sucursales tablaSucursales;
  int indice = 0;
  int acumulador = 0;
  
  nSucursales = fopen("SucTop.dat","rb");
  nNovedades = fopen("novedades.dat","rb");
  aFinal = fopen("SucArgGra.dat", "wb");

  fread(&sucursal, sizeof(TRegSuc),1,nSucursales);
  while(!feof(nSucursales)){
    if(sucursal.cantidadEmpleados > 100){
      tablaSucursales[indice] = sucursal;
      indice++;//el indice se usa para calcular la cantidad total de elementos que cumplen
    }
    fread(&sucursal, sizeof(TRegSuc),1,nSucursales);
  }//esto termina con la primera sucursal.
  
  fread(&sucursal, sizeof(TRegSuc),1,nNovedades);
  while(!feof(nNovedades)){
    if(sucursal.cantidadEmpleados > 100){
      tablaSucursales[indice] = sucursal;
      indice++;
    }
    fread(&sucursal, sizeof(TRegSuc),1,nNovedades);
  }//termina de leer los datos de la segunda sucursal.
  
  for(int i = 0; i < indice - 1; i++){
    for(int j = 0; j < indice - i - 1; j++){
      if(tablaSucursales[j].codigo > tablaSucursales[j+1].codigo){
        aux = tablaSucursales[j];
        tablaSucursales[j] = tablaSucursales[j+1];
        tablaSucursales[j+1] = aux;
      }
    }
  }//esto se encarga del burbujeo de las sucursales por el codigo, para que queden de menor a mayor
  
  while(acumulador < indice){
    fwrite(&tablaSucursales[acumulador], sizeof(TRegSuc), 1, aFinal);
    acumulador++;
  }
  fclose(nSucursales);
  fclose(nNovedades);
  fclose(aFinal);
}

int main(){
  FILE *nSucursales, *nNovedades, *aFinal;
  adjuntarSucursal(nSucursales,nNovedades,aFinal);
  return 0;
}
