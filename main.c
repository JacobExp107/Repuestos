#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
 
int main() {
    int n = 8;  
    char repuestos[20][50]; 
    int inventario[20] = {10, 15, 20, 5, 8, 2, 3, 7};
    int ventas[20] = {0};
    float precios[20] = {50.0, 80.0, 25.0, 120.0, 60.0, 500.0, 300.0, 200.0};
 
    
    strcpy(repuestos[0], "Llantas");
    strcpy(repuestos[1], "Amortiguadores");
    strcpy(repuestos[2], "Sensores");
    strcpy(repuestos[3], "Puertas");
    strcpy(repuestos[4], "Ventanas");
    strcpy(repuestos[5], "Motor");
    strcpy(repuestos[6], "Caja de cambios");
    strcpy(repuestos[7], "Chasis");
 
    char opcion;
    char nombreRepuesto[50];
    int cantidad;
    float costoUnitario;
 
    while (1) {
        printf("\n--- Menú de Transacciones ---\n");
        printf("1. Realizar venta\n");
        printf("2. Realizar compra\n");
        printf("3. Mostrar inventario\n");
        printf("4. Mostrar costo total del inventario\n");
        printf("5. Salir\n");
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);
 
        switch (opcion) {
            case '1':
                printf("Ingrese el nombre del repuesto a vender: ");
                scanf("%s", nombreRepuesto);
                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidad);
                realizarVenta(repuestos, inventario, ventas, precios, n, nombreRepuesto, cantidad);
                break;
            case '2':
                printf("Ingrese el nombre del repuesto a comprar: ");
                scanf("%s", nombreRepuesto);
                printf("Ingrese la cantidad a comprar: ");
                scanf("%d", &cantidad);
                printf("Ingrese el costo unitario para la compra: ");
                scanf("%f", &costoUnitario);
                realizarCompra(repuestos, inventario, &n, nombreRepuesto, cantidad, costoUnitario);
                break;
            case '3':
                mostrarInventario(repuestos, inventario, n);
                break;
            case '4':
                mostrarCostoTotal(repuestos, inventario, precios, n);
                break;
            case '5':
                exit(0);  
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    }
 
    return 0;
}