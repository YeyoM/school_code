#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date {
    int dia;
    int mes;
    int anio;
} fecha1, fecha2, fecha3;


int main() {
    fecha1.dia = 23;
    fecha1.mes = 11;
    fecha1.anio = 2020;

    fecha1.dia = 10;
    fecha1.mes = 1;
    fecha1.anio = 2010;

    fecha1.dia = 4;
    fecha1.mes = 8;
    fecha1.anio = 2021;

    //imprimir
    return 0;
}