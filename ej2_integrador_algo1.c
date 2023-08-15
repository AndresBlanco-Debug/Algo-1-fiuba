#include <stdio.h>

/*SE LOCITIDA DESARROLLAR UNA FUNCION QUE RECIBA DICHA TABLA Y SU MAXIMO LOGICO Y QUE DEVUELVA EL MONTO TOTAL VENDIDO DURANTE EL DIA CONSIDERANDO UNICAMENTE AQUELLAS OPERACIONES CUYO CODIGO DE OPERACION SEA MENOR A 700
Y LA CANTIDAD DE REGISTROS QUE CUMPLIERON CON DICHA CONDICION*/

#define TAMANO 1000
typedef struct{
int Cod_Ope;//Codigo de operacion
int Cod_Remedio;//Codigo de remedio vendido
float Prec_Unit;//Precio unitario del producto
int Cantidad;//Cantidad de unidades vendidas
} TReg_Ventas;

//variables
TReg_Ventas Tabla[TAMANO];
int ML_tabla;//maximo logico de la tabla

void generarTabla(TReg_Ventas Tabla[TAMANO], int *ML_tabla){
  *ML_tabla = 0;
  int montoVendido = 0, cantidadRegistros = 0;
  
  for(int i = 0; i < 1000; i++){
    if(Tabla[i].Cod_Ope < 700){
      cantidadRegistros++;
      montoVendido = montoVendido + (Tabla[i].Prec_Unit * Tabla[i].Cantidad);
    }
  }
  if(montoVendido < cantidadRegistros){
    *ML_tabla = cantidadRegistros;
  }else{
    *ML_tabla = montoVendido;
  }
}
