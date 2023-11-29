#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
void mostrarInventario(char repuestos[][50], int inventario[], int n) {
    printf("Inventario de Repuestos:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s: %d unidades\n", repuestos[i], inventario[i]);
    }
    printf("\n");
}
 
void realizarVenta(char repuestos[][50], int inventario[], int ventas[], float precios[], int n, char repuesto[], int cantidad) {
    int idRepuesto = -1;
    for (int i = 0; i < n; ++i) {
        if (strcmp(repuestos[i], repuesto) == 0) {
            idRepuesto = i;
            break;
        }
    }
 
    if (idRepuesto != -1) {
        if (inventario[idRepuesto] >= cantidad) {
            inventario[idRepuesto] -= cantidad;
            ventas[idRepuesto] += cantidad;
            printf("Venta de %s realizada con éxito.\n", repuesto);
        } else {
            printf("No hay suficientes unidades disponibles en el inventario de %s.\n", repuesto);
        }
    } else {
        printf("Repuesto no encontrado.\n");
    }
}
 
void realizarCompra(char repuestos[][50], int inventario[], int *n, char repuesto[], int cantidad, float costoUnitario) {
    int idRepuesto = -1;
    for (int i = 0; i < *n; ++i) {
        if (strcmp(repuestos[i], repuesto) == 0) {
            idRepuesto = i;
            break;
        }
    }
 
    if (idRepuesto != -1) {
        inventario[idRepuesto] += cantidad;
        printf("Compra de %s realizada con éxito. Unidades aumentadas a %d.\n", repuesto, inventario[idRepuesto]);
    } else {
        
        strcpy(repuestos[*n], repuesto);
        inventario[*n] = cantidad;
        (*n)++;
        printf("Nuevo repuesto %s agregado con %d unidades.\n", repuesto, cantidad);
    }
}
 
void mostrarCostoTotal(char repuestos[][50], int inventario[], float precios[], int n) {
    float costoTotal = 0;
    for (int i = 0; i < n; ++i) {
        costoTotal += inventario[i] * precios[i];
    }
    printf("Costo total del inventario: %.2f\n", costoTotal);
}