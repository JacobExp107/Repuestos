#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define Espacio_Vehiculos 100
#define cost_min 0.025

char modelo[Espacio_Vehiculos][50];
char color[Espacio_Vehiculos][20];
float t_ingreso[Espacio_Vehiculos];
float t_salida[Espacio_Vehiculos];

int registroIngreso = 0;

void registrarEntrada() {
    if (registroIngreso < Espacio_Vehiculos) {
        printf("Ingrese el modelo del vehículo: ");
        scanf("%s", modelo[registroIngreso]);

        printf("Ingrese el color del vehículo: ");
        scanf("%s", color[registroIngreso]);

        printf("Ingrese el tiempo de entrada en minutos: ");
        scanf("%f", &t_ingreso[registroIngreso]);

        printf("Vehículo registrado con éxito.\n\n");

        registroIngreso++;
    } else {
        printf("El parqueadero está lleno. No se pueden registrar más vehículos.\n\n");
    }
}

void registrarSalida() {
    if (registroIngreso > 0) {
        int indice = 0;
        printf("Ingrese el índice del vehículo que sale (0-%d): ", registroIngreso - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < registroIngreso) {
            printf("Ingrese el tiempo de salida en minutos: ");
            scanf("%f", &t_salida[indice]);

            printf("Vehículo marcado como salida.\n");

            float tiempoParqueado = t_salida[indice] - t_ingreso[indice];
            float valorPagar = tiempoParqueado * cost_min;

            printf("Tiempo de parqueadero: %.2f minutos\n", tiempoParqueado);
            printf("Valor a pagar: $%.2f\n\n", valorPagar);
        } else {
            printf("Índice inválido.\n\n");
        }
    } else {
        printf("No hay vehículos registrados en el parqueadero.\n\n");
    }
}

void imprimirInformacion() {
    if (registroIngreso > 0) {
        printf("------ Vehículos en el parqueadero ------\n");
        for (int i = 0; i < registroIngreso; i++) {
            printf("------ Vehículo %d ------\n", i + 1);
            printf("Modelo: %s\n", modelo[i]);
            printf("Color: %s\n", color[i]);
            printf("Tiempo de entrada: %.2f minutos\n", t_ingreso[i]);

            if (t_salida[i] != 0) {
                printf("Tiempo de salida: %.2f minutos\n", t_salida[i]);
                float tiempoParqueado = t_salida[i] - t_ingreso[i];
                printf("Tiempo de parqueadero: %.2f minutos\n", tiempoParqueado);
                printf("Estado: Pagado\n");
            } else {
                printf("Estado: Parqueado\n");
            }

            printf("\n");
        }
    } else {
        printf("No hay vehículos registrados en el parqueadero.\n\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define Espacio_Vehiculos 100
#define cost_min 0.025

char modelo[Espacio_Vehiculos][50];
char color[Espacio_Vehiculos][20];
float t_ingreso[Espacio_Vehiculos];
float t_salida[Espacio_Vehiculos];

int registroIngreso = 0;

void registrarEntrada() {
    if (registroIngreso < Espacio_Vehiculos) {
        printf("Ingrese el modelo del vehículo: ");
        scanf("%s", modelo[registroIngreso]);

        printf("Ingrese el color del vehículo: ");
        scanf("%s", color[registroIngreso]);

        printf("Ingrese el tiempo de entrada en minutos: ");
        scanf("%f", &t_ingreso[registroIngreso]);

        printf("Vehículo registrado con éxito.\n\n");

        registroIngreso++;
    } else {
        printf("El parqueadero está lleno. No se pueden registrar más vehículos.\n\n");
    }
}

void registrarSalida() {
    if (registroIngreso > 0) {
        int indice = 0;
        printf("Ingrese el índice del vehículo que sale (0-%d): ", registroIngreso - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < registroIngreso) {
            printf("Ingrese el tiempo de salida en minutos: ");
            scanf("%f", &t_salida[indice]);

            printf("Vehículo marcado como salida.\n");

            float tiempoParqueado = t_salida[indice] - t_ingreso[indice];
            float valorPagar = tiempoParqueado * cost_min;

            printf("Tiempo de parqueadero: %.2f minutos\n", tiempoParqueado);
            printf("Valor a pagar: $%.2f\n\n", valorPagar);
        } else {
            printf("Índice inválido.\n\n");
        }
    } else {
        printf("No hay vehículos registrados en el parqueadero.\n\n");
    }
}

void imprimirInformacion() {
    if (registroIngreso > 0) {
        printf("------ Vehículos en el parqueadero ------\n");
        for (int i = 0; i < registroIngreso; i++) {
            printf("------ Vehículo %d ------\n", i + 1);
            printf("Modelo: %s\n", modelo[i]);
            printf("Color: %s\n", color[i]);
            printf("Tiempo de entrada: %.2f minutos\n", t_ingreso[i]);

            if (t_salida[i] != 0) {
                printf("Tiempo de salida: %.2f minutos\n", t_salida[i]);
                float tiempoParqueado = t_salida[i] - t_ingreso[i];
                printf("Tiempo de parqueadero: %.2f minutos\n", tiempoParqueado);
                printf("Estado: Pagado\n");
            } else {
                printf("Estado: Parqueado\n");
            }

            printf("\n");
        }
    } else {
        printf("No hay vehículos registrados en el parqueadero.\n\n");
    }
}
