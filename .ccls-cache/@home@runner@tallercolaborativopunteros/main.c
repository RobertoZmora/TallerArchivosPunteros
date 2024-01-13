#include <stdio.h>
#include "lecturas.h"
#include "funciones.h"
#include "menu.h"

#define FILAS 100
#define COLUMNAS 15

FILE *archivo;

int main() {
    char producto[FILAS][COLUMNAS];
    int cantidadProductos[FILAS];
    float precio[FILAS];
    printf("Bienvenido al inventario de MEGAMAXI´\n Menu principal \n");
    if ((archivo = fopen("inventario.txt", "a+")) != NULL) {
        int tamaño;
        int op;
        do {
            op = mostrarMenu();
            switch (op) {
                case 1:
                    ingresarDatos(&tamaño, producto, precio, cantidadProductos);
                    guardarDatos(tamaño, producto, precio, cantidadProductos);
                    break;
                case 2:
                    editarDatos(tamaño, producto, precio, cantidadProductos);
                    guardarDatos(tamaño, producto, precio, cantidadProductos);
                    break;
                case 3:
                    mostrarDatos(tamaño, producto, precio, cantidadProductos);
                    break;
            }
        } while (op != 4);
    } else {
        printf("El archivo no pudo abrirse\n");
    }

    fclose(archivo);
    return 0;
}