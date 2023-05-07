#include<stdio.h>
#include<ctype.h>

int main()
{
    char nombre[1000];
    char cedula[20];

    float precioA = 150, precioB = 55, precioC = 180, precioD = 70, precioE = 120;
    float numA = 0, numB = 0, numC = 0, numD = 0, numE = 0;
    float subtotalA = 0, subtotalB, subtotalC, subtotalD, subtotalE = 0;
    float subtotal = 0, total = 0;

    char opcion = 'f';
    int menu = 0;

    subtotal = precioA * numA;
    subtotal = precioB * numB;
    subtotal = precioC * numC;
    subtotal = precioD * numD;
    subtotal = precioE * numE;

    subtotal = subtotalA + subtotalB + subtotalC + subtotalD, subtotalE;

    
    do
    {
        printf("1) Cotizar Factura\n");
        printf("2) Facturacion");
        printf("3) Salir");

        switch (menu)
        {
            case 3:
            printf("Hola");

        }
    }while(menu!= 4);
}