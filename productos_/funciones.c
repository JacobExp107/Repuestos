#include "funciones.h"

void ingresarProducto(FILE *archivo) {
    char nuevoProducto[20];
    char cantProducto[20];

    for (int i = 0; i < 3; i++) 
    {
      printf("Ingrese el nombre del producto:");
      fgets(nuevoProducto, 20, stdin);
      nuevoProducto[strcspn(nuevoProducto, "\n")] = 0;
      printf("Ingrese la cantidad del producto:");
      fgets(cantProducto,20,stdin);
      cantProducto[strcspn(cantProducto, "\n")] = 0;
      fputs(nuevoProducto,archivo);
      fputs("-",archivo); 
      fputs(cantProducto,archivo);
      fputs("\n",archivo);
    }
}

void buscarProducto(FILE *archivo) {
    char productoBuscar[50];
    int encontrado = 0;
    printf("Ingrese el producto a buscar: ");
    fgets(productoBuscar,50,stdin);
    productoBuscar[strcspn(productoBuscar, "\n")] = 0;

    rewind(archivo);

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
}
