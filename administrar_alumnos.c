#include <stdio.h>

/*Dada la siguiente estructura:
typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;


Escribir un programa modular que permita almacenar y consultar datos en un archivo alumnos.

El programa deberá tener un menú con las siguientes opciones:
1 - Cargar Datos Alumnos
2 - Listar Alumnos
3 - Salir
Los datos que se guardan de los alumnos son los indicados en la estructura inicial.
La carga de datos, termina cuando el padron ingresado sea 0.
La carga de datos, puede reanudarse, y en este caso no se deben perder los datos existentes.
El listado debe ser de todos los datos, encolumnados, y en el orden que se encuentran almacenados.*/

typedef struct {
    int padron;
    char ape_nom[30];
    float nota;
}t_regAlumno;

void ingresar_datos(FILE *ubaAlumnos){
     // se usa la estructura de datos definida para crear la variable alumnos;
     t_regAlumno algoAlumno;

    printf("Ingrese el padron del alumno: ");
    scanf("%d",&algoAlumno.padron);
    fflush(stdin);

    while(algoAlumno.padron != 0){
        printf("\nIngrese el apellido y nombre: ");
        scanf("%30[^\n]s",algoAlumno.ape_nom);
        fflush(stdin);

        printf("\nIngrese la nota: ");
        scanf("%f",&algoAlumno.nota);
        fflush(stdin);

        fwrite(&algoAlumno,sizeof(algoAlumno),1,ubaAlumnos);

        printf("\nIngrese el padron del alumno: ");
        scanf("%d",&algoAlumno.padron);
        fflush(stdin);
    }
}

void leer_alumnos(FILE *ubaAlumnos){

    t_regAlumno algoAlumnos;

    fread(&algoAlumnos,sizeof(algoAlumnos),1,ubaAlumnos);
    printf("\nPadron \tApellido y Nombre \t\t\tNota");

    while(!feof(ubaAlumnos)){
        printf("\n %d \t%-30s \t%f.2f",algoAlumnos.padron,algoAlumnos.ape_nom,algoAlumnos.nota);
        fread(&algoAlumnos,sizeof(algoAlumnos),1,ubaAlumnos);
    }
}

int main(){
    FILE *ubaAlumnos;

    ubaAlumnos = fopen("alumnos.dat","a+b");
    if(ubaAlumnos == NULL){
        printf("\nEl archivo no se puede abrir!\n");
    }
    else{
        ingresar_datos(ubaAlumnos);
        rewind(ubaAlumnos);
        leer_alumnos(ubaAlumnos);
        fclose(ubaAlumnos);
    }
    return 0;
}
