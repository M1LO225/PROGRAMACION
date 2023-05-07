#include <stdio.h>

int main(int argc, char *argv[])
{

    char nombre[1000];
    char cedula[20];

    float precioA = 150, precioB = 55, precioC = 180, precioD = 70, precioE = 120;
    float numA = 0, numB = 0, numC = 0, numD = 0, numE = 0;
    float subtotalA = 0, subtotalB, subtotalC, subtotalD, subtotalE = 0;
    float subtotal = 0, total = 0;

    char opcion= 'f';

    printf("**********Escoja un producto que desee facturar: **********\n");
    printf("a) Llantas (Precio: $150)\n");
    printf("b) Kit Pastillas de freno (Precio: $55)\n");
    printf("c) Kit de embrague (Precio: $180)\n");
    printf("d) Faro (Precio: $70)\n");
    printf("e) Radiador (Precio: $120)\n");
    scanf("%c" ,&opcion);

    switch (opcion)
    {
    case 'a':
        printf("ingrese el numero de Llantas: \n");
        scanf("%f", &numA);
        break;

        case 'b':
        printf("ingrese el numero de Kit de pastillas de frenos: \n");
        scanf("%f", &numB);
        break;
       
        case 'c':
        printf("ingrese el numero de Kit de embargue: \n");
        scanf("%f", &numC);
        break;
       
        case 'd':
        printf("ingrese el numero de Faros: \n");
        scanf("%f", &numD);
        break;

        case 'e':
        printf("ingrese el numero de Radiadores:\n");
        scanf("%f", &numE);
        break;

        default:
            break;
                   
    }

    subtotal=precioA*numA;
    subtotal=precioB*numB;
    subtotal=precioC*numC;
    subtotal=precioD*numD;
    subtotal=precioE*numE;

    subtotal=subtotalA+subtotalB+subtotalC+subtotalD,subtotalE;

    if (subtotal>100 && subtotal <5000)
    {
        total=subtotal - subtotal*0.05;
    }
    else if (subtotal>500 && subtotal<=1000)
    {
        total=subtotal-subtotal*0.07;
    }
    else if (subtotal>1000)
    {
        total=subtotal-subtotal*0.01;
    }
 
    printf("ingrese el nombre del cliente: \n");
    scanf("%s", &nombre );
    printf("ingrese la cedula del cliente: \n");
    scanf("%s", &cedula );

    printf("********Datos del Cliente********\n");
    printf("Nombre: %s\n", nombre);
    printf("Cedula: %s\n", cedula);
    printf("*********Factura*********\n");
    printf("Producto             Cantidad              Precio Unitario               Precio total\n");
    if (numA!=0)
    {
        printf("Llantas            %f                     %f                %-2f\n",numA,precioA,subtotalA);    
    }
    if (numB!=0)
    {
        printf("Kit frenos          %f                      %f                %-2f\n",numB,precioB,subtotalB);    
    }
    if (numC!=0)
    {
        printf("Kit embrague            %f                  %f                %-2f\n",numC,precioC,subtotalC);    
    }
    if (numD!=0)
    {
        printf("Faros            %f                        %f                %-2f\n",numD,precioD,subtotalD);    
    }
    if (numE!=0)
    {
        printf("Radidador            %f                     %f                %-2f\n",numE,precioE,subtotalE);    
    }
       
    printf("El subtotal es: %f\n",subtotal);
    printf("El total es: %f\n",total);
    return 0;
}