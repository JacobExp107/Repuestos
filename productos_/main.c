#include "funciones.h"

int main (int argc, char *argv[]) {
    FILE *archivo;
    archivo = fopen("archivo1.txt", "w+");

    if (archivo == NULL) 
    {
        printf("No se pudo crear el archivo");
        return 0;
    }

    ingresarProducto(archivo);

    fclose(archivo);

    archivo = fopen("archivo1.txt", "r+");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo");
        return 0;
    }

    buscarProducto(archivo);

    fclose(archivo);
    return 0;
}
