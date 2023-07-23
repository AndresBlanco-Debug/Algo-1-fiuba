#include <stdio.h>

int cantidad_dias(int mes) {
    int dias;
    if (mes == 2) {
        dias = 28;
    } else if ((mes < 7 && mes % 2 == 0) || (mes > 7 && mes % 2 != 0)) {
        dias = 30;
    } else {
        dias = 31;
    }
    return dias;
}

void generar_matriz(int tabla[24][31], int mes) {
    for (int dia = 1; dia <= cantidad_dias(mes); dia++) { // Corregimos el límite del for para incluir el último día
        for (int hora = 0; hora < 24; hora++) {
            printf("Ingrese la temperatura en la hora %d del dia %d: ", hora, dia); // Corregimos el mensaje de ingreso
            scanf("%d", &tabla[hora][dia]);
        }
    }
}

void valor_maximo(int tabla[24][31], int *maximo_por_dia, int *maximo_por_mes, int *minimo_por_mes, int *minimo_por_dia) {
    *minimo_por_dia = 0;
    *maximo_por_dia = 0;
    *maximo_por_mes = 0;
    *minimo_por_mes = tabla[0][1]; // Inicializamos el mínimo del mes con el valor del primer día

    for (int dias = 1; dias <= 31; dias++) { // Corregimos el límite del for para incluir el último día
        for (int horas = 0; horas < 24; horas++) {
            if (tabla[horas][dias] > *maximo_por_dia) {
                *maximo_por_dia = tabla[horas][dias];
            }
            if (tabla[horas][dias] < *minimo_por_dia) {
                *minimo_por_dia = tabla[horas][dias];
            }
            if (tabla[horas][dias] > *maximo_por_mes) {
                *maximo_por_mes = tabla[horas][dias];
            }
            if (tabla[horas][dias] < *minimo_por_mes) {
                *minimo_por_mes = tabla[horas][dias];
            }
        }
    }
}

int main() {
    int mes;
    printf("Ingrese el numero de mes: ");
    scanf("%d", &mes);

    int dias = cantidad_dias(mes);
    int tabla[24][31]; // Definimos la matriz para almacenar las temperaturas

    // Cargamos los datos en la matriz
    generar_matriz(tabla, mes);

    // Calculamos los valores máximos y mínimos
    int maximo_por_dia, maximo_por_mes, minimo_por_mes, minimo_por_dia;
    valor_maximo(tabla, &maximo_por_dia, &maximo_por_mes, &minimo_por_mes, &minimo_por_dia);

    // Imprimimos la matriz
    printf("\nListado de temperaturas:\n");
    for (int dia = 1; dia <= dias; dia++) {
        for (int hora = 0; hora < 24; hora++) {
            printf("%d ", tabla[hora][dia]);
        }
        printf("\n");
    }

    // Mostramos los resultados
    printf("\nTemperatura maxima del mes: %d\n", maximo_por_mes);
    printf("Temperatura minima del mes: %d\n", minimo_por_mes);
    printf("Temperatura maxima por dia:\n");
    for (int dia = 1; dia <= dias; dia++) {
        printf("Dia %d: %d\n", dia, tabla[0][dia]); // Imprimimos la temperatura máxima de cada día (hora 0)
    }
    printf("Temperatura minima por dia:\n");
    for (int dia = 1; dia <= dias; dia++) {
        printf("Dia %d: %d\n", dia, tabla[12][dia]); // Imprimimos la temperatura mínima de cada día (hora 12)
    }

    return 0;
