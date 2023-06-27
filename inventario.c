#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 

void ingresarProducto(int ID[], char nombre[][50], float precio[], int stock[], int *bloque);
void verProductos(int ID[], char nombre[][50], float precio[], int stock[], int bloque);
void modificarProducto(int ID[], char nombre[][50], float precio[], int stock[], int bloque);
void eliminarProducto(int ID[], char nombre[][50], float precio[], int stock[], int *bloque);

int main() {
    int menu, bloque = 0;
    int ID[MAX], stock[MAX];
    char nombre[MAX][50];
    float precio[MAX];

    do {
        printf("\n-- COFRE --\n");
        printf("\n1. Ingresar un bloque");
        printf("\n2. Ver Bloques");
        printf("\n3. Modificar un bloque");
        printf("\n4. Eliminar un bloque");
        printf("\n5. Salir");
        printf("\n\nIngrese una opcion: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                ingresarProducto(ID, nombre, precio, stock, &bloque);
                break;
            case 2:
                verProductos(ID, nombre, precio, stock, bloque);
                break;
            case 3:
                modificarProducto(ID, nombre, precio, stock, bloque);
                break;
            case 4:
                eliminarProducto(ID, nombre, precio, stock, &bloque);
                break;
            case 5:
                printf("\nSaliendo del programa...\n\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
                break;
        }

    } while(menu != 5);

    return 0;
}

void ingresarProducto(int ID[], char nombre[][50], float precio[], int stock[], int *bloque) {
    if (*bloque < MAX) {
        printf("\nIngrese el ID del bloque: ");
        scanf("%d", &ID[*bloque]);
        printf("Ingrese el nombre del bloque: ");
        scanf("%s", nombre[*bloque]);
        printf("Ingrese el precio del bloque: ");
        scanf("%f", &precio[*bloque]);
        printf("Ingrese el stock del bloque: ");
        scanf("%d", &stock[*bloque]);

        (*bloque)++;

        printf("\nBloque ingresado exitosamente.\n");
    } else {
        printf("\nNo se pueden ingresar mas bloques. Limite alcanzado.\n");
    }
}

void verProductos(int ID[], char nombre[][50], float precio[], int stock[], int bloque) {
    if (bloque > 0) {
        printf("\n-- LISTA DE BLOQUES --\n");
        printf("\nID\tNombre\t\tPrecio\tStock");
        for (int i = 0; i < bloque; i++) {
            printf("\n%d\t%s\t\t%.2f\t%d", ID[i], nombre[i], precio[i], stock[i]);
        }
    } else {
        printf("\nNo hay bloques ingresados.\n");
    }
}

void modificarProducto(int ID[], char nombre[][50], float precio[], int stock[], int bloque) {
    int modificar, check = 0;
    printf("\nIngrese el ID del bloque que desea modificar: ");
    scanf("%d", &modificar);

    for (int i = 0; i < bloque; i++) {
        if (modificar == ID[i]) {
            printf("Ingrese el nuevo nombre del bloque: ");
            scanf("%s", nombre[i]);
            printf("Ingrese el nuevo precio del bloque: ");
            scanf("%f", &precio[i]);
            printf("Ingrese el nuevo stock del bloque: ");
            scanf("%d", &stock[i]);
            check = 1;
            printf("\nBloque modificado exitosamente.\n");
            break;
        }
    }

    if (!check) {
        printf("\nEl ID ingresado no corresponde a ningun bloque.\n");
    }
}

void eliminarProducto(int ID[], char nombre[][50], float precio[], int stock[], int *bloque) {
    int eliminar, check = 0;
    printf("\nIngrese el ID del producto que desea eliminar: ");
    scanf("%d", &eliminar);

    for (int i = 0; i < *bloque; i++) {
        if (eliminar == ID[i]) {
            for (int j = i; j < *bloque - 1; j++) {
                ID[j] = ID[j+1];
                strcpy(nombre[j], nombre[j+1]);
                precio[j] = precio[j+1];
                stock[j] = stock[j+1];
            }
            (*bloque)--;
            check = 1;
            printf("\nBloque eliminado exitosamente.\n");
            break;
        }
    }

    if (!check) {
        printf("\nEl ID ingresado no corresponde a ningun bloque.\n");
    }
}