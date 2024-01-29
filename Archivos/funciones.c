#include <stdio.h>
#include "funciones.h"

void cargarProductos() {
    FILE *archivo;
    archivo = fopen("archivo1.txt", "w");

    if (archivo == NULL) 
    {
        printf("No se pudo abrir el archivo");
        return;
    }

    char nomProduc[10][50] = {"queso", "tomates", "yogurt", "papas", "carne", "pollo", "leche", "huevo", "aguacate"};
    int cantProduc[10] = {5, 6, 2, 6, 10, 5, 5, 11, 10, 0};

    for (int i = 0; i < 10; i++) {
        fputs(nomProduc[i], archivo);
        fputs("-", archivo);
        char cantStr[10];
        sprintf(cantStr, "%d", cantProduc[i]);
        fputs(cantStr, archivo);
        fputs("\n", archivo);
    }

    fclose(archivo);
}

void ingresarProducto() {
    FILE *archivo;
    archivo = fopen("archivo1.txt", "a+");

    if (archivo == NULL) 
    {
        printf("No se pudo abrir el archivo");
        return;
    }

    char nuevoProducto[20];
    char cantProducto[20];

    for (int i = 0; i < 1; i++) 
    {
      printf("Ingrese el nombre del producto:");
      fgets(nuevoProducto, 20, stdin);
      nuevoProducto[strcspn(nuevoProducto, "\n")] = 0;// Elimina el carácter de nueva línea
      printf("Ingrese la cantidad del producto:");
      fgets(cantProducto,20,stdin);
      cantProducto[strcspn(cantProducto, "\n")] = 0;
      fputs(nuevoProducto,archivo);
      fputs("-",archivo); 
      fputs(cantProducto,archivo);
      fputs("\n",archivo);
    }

    fclose(archivo);
}

void buscarProducto() {
    FILE *archivo;
    archivo = fopen("archivo1.txt", "r");

    if (archivo == NULL) 
    {
        printf("No se pudo abrir el archivo");
        return;
    }

    char productoBuscar[50];
    int encontrado = 0;
    printf("Ingrese el producto a buscar: ");
    fgets(productoBuscar,50,stdin);
    productoBuscar[strcspn(productoBuscar, "\n")] = 0;

    char line[100];
    while (fgets(line, sizeof(line), archivo)!=NULL) {
        char *producto = strtok(line, "-");
        char *cantidad = strtok(NULL, "-");
        if(producto && strcmp(producto, productoBuscar) == 0){
           printf("La cantidad del producto es: %s", cantidad);
           encontrado = 1;
           break;
        }
    } 

    if (!encontrado) {
        printf("El producto no se encontró en el archivo.\n");
    }

    fclose(archivo);
}
