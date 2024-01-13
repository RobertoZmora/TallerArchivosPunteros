#include <stdio.h>
#include "funciones.h"
#define FILAS 100
#define COLUMNAS 15
FILE*archivo;

void ingresarDatos(int *cantidad, char productos[][COLUMNAS], float precio[], int cantidadProductos[]) {
    printf("Ingrese el numero de productos\n");
    int num;
    scanf("%d", &num);
    *cantidad = num;
    for (int i = 0; i < *cantidad; i++) {
        printf("Ingrese el nombre del producto %d: \n", i + 1);
        scanf("%s", productos[i]);
        printf("Ingrese la cantidad del producto %d: \n", i + 1);
        scanf("%d", &cantidadProductos[i]);
        printf("Ingrese el precio del producto %d: \n", i + 1);
        scanf("%f", &precio[i]);
    }
}

void guardarDatos(const int cantidad, const char productos[][COLUMNAS], const float precio[], const int cantidadProductos[]) {
    if ((archivo = fopen("inventario.txt", "a+")) != NULL) {
        for (int i = 0; i < cantidad; i++) {
            fputs(productos[i], archivo);
            fputs(" ", archivo);
            fprintf(archivo, "%d", cantidadProductos[i]);
            fputs(" ", archivo);
            fprintf(archivo, "%.2f", precio[i]);
            fputs("\n", archivo);
        }
    } else
        printf("El archivo no pudo abrirse\n");

    fclose(archivo);
}

void editarDatos(const int cantidad, char productos[][COLUMNAS], float precio[], int cantidadProductos[]) {
    if ((archivo = fopen("inventario.txt", "r+")) != NULL) {
        printf("Ingrese el nombre del producto que desea editar: \n");
        char producto[50];
        scanf("%s", producto);
        rewind(archivo);
        for (int i = 0; i < cantidad; i++) {
            if (strcmp(producto, productos[i]) == 0) {
                fseek(archivo, sizeof(char) * COLUMNAS, SEEK_SET);
                printf("Ingrese la cantidad del producto: \n");
                scanf("%d", &cantidadProductos[i]);
                printf("Ingrese el precio del producto: \n");
                scanf("%f", &precio[i]);
                break;
            }
        }
    } else
        printf("El archivo no pudo abrirse\n");

    fclose(archivo);
}

void mostrarDatos(const int cantidad, char productos[][COLUMNAS], float precio[], int cantidadProductos[]) {
    if ((archivo = fopen("inventario.txt", "r")) != NULL) {
        printf("Lista de productos:\n");
        for (int i = 0; i < cantidad; i++) {
            fscanf(archivo, "%s %d %f", productos[i], &cantidadProductos[i], &precio[i]);
            printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", productos[i], cantidadProductos[i], precio[i]);
        }
    } else {
        printf("El archivo no pudo abrirse\n");
    }

    fclose(archivo);
}