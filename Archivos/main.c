#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    cargarProductos();

    int opcion;
    do {
        printf("Elige una opción:\n");
        printf("1. Ingresar un producto\n");
        printf("2. Buscar un producto\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);
        getchar(); 

        switch(opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                buscarProducto();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
