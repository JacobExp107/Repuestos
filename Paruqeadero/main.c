#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int opcion;

    while (1) {
        printf("------ Menu ------\n");
        printf("1. Registrar entrada de vehículo\n");
        printf("2. Registrar salida de vehículo\n");
        printf("3. Imprimir información de vehículos\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarEntrada();
                break;

            case 2:
                registrarSalida();
                break;

            case 3:
                imprimirInformacion();
                break;

            case 4:
                printf("Saliendo del programa.\n");
                exit(0);  
                break;

            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n\n");
                break;
        }
    }

    return 0;
}
