#include <stdio.h>
#include <string.h>
#include "funciones.h"

void editarProducto(char nombres[][50], int cantidades[], float precios[], int numProductos) {
    int indice;

    printf("Ingrese el índice del producto que desea editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numProductos) {
        printf("Ingrese el nuevo nombre del producto :\n ");
        scanf("%s", nombres[indice]);

        printf("Ingrese la nueva cantidad en stock: \n");
        scanf("%d", cantidades[indice]);

        printf("Ingrese el nuevo precio por unidad: \n");
        scanf("%f", precios[indice]);

        printf("Producto editado en el inventario de Megamaxi con éxito.\n");
    } else {
        printf("Índice no válido. No se pudo editar el producto.\n");
    }
}

void eliminarProducto(char nombres[][50], int cantidades[], float precios[], int numProductos) {
    int indice;

    printf("Ingrese el índice del producto que desea eliminar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numProductos) {
        for (int i = indice; i < numProductos - 1; ++i) {
            for (int j = 0; j < 50; ++j) {
                nombres[i][j] = nombres[i + 1][j];
            }
            cantidades[i] = cantidades[i + 1];
            precios[i] = precios[i + 1];
        }

        printf("Producto eliminado del inventario de Megamaxi con éxito.\n");
    } else {
        printf("Índice no válido. No se pudo eliminar el producto.\n");
    }
}

void listarProductos(char nombres[][50], int cantidades[], float precios[], int numProductos) {
    if (numProductos > 0) {
        printf("Inventario de Megamaxi:\n");
        for (int i = 0; i < numProductos; ++i) {
            printf("Índice: %d\n", i);
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad en stock: %d\n", cantidades[i]);
            printf("Precio por unidad: %.2f\n", precios[i]);
            printf("------------------------\n");
        }
    } else {
        printf("El inventario de Megamaxi está vacío.\n");
    }
}