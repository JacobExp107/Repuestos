#ifndef FUNCIONES_H
#define FUNCIONES_H
 
void mostrarInventario(char repuestos[][50], int inventario[], int n);

void realizarVenta(char repuestos[][50], int inventario[], int ventas[], float precios[], int n, char repuesto[], int cantidad);

void realizarCompra(char repuestos[][50], int inventario[], int *n, char repuesto[], int cantidad, float costoUnitario);

void mostrarCostoTotal(char repuestos[][50], int inventario[], float precios[], int n);
 
#endif 
