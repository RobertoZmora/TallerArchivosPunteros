#include <stdio.h>
#include "menu.h"

int mostrarMenu() {
    int opcion;

    printf("\nMenú de Inventario Megamaxi:\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    return opcion;
}