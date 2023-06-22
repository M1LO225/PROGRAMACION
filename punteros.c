#include <stdio.h>
#include <math.h>
float calculoDistancia (float x1, float y1, float z1, float x2, float y2, float z2);
void calcularPerimetro(float puntos [4][3], float *per1, float *per2, float *per3, float *per4, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6);
float calcularArea(float per1, float l1, float l2, float l3);
float calcularAreaSuperficial(float area1, float area2, float area3, float area4);
float calcularAltura(float puntos [4][3]);
float calcularVolumen(float area1, float altura);

int main (int argc, char *argv[]) {
    float puntos [4][3]= {{0,0,3} , {3,0,0} , {0,0,0}, {1,7,1}};
    float per1, per2, per3, per4, l1, l2, l3, l4, l5, l6;
    calcularPerimetro(puntos, &per1, &per2, &per3, &per4, &l1, &l2, &l3, &l4, &l5, &l6);
    float area1= calcularArea(per1, l1, l2, l3);
    float area2= calcularArea(per2, l2, l4, l6);
    float area3= calcularArea(per3, l3, l5, l6);
    float area4= calcularArea(per4, l1, l5, l4);
    float AS= calcularAreaSuperficial(area1, area2, area3, area4);
    float altura= calcularAltura(puntos);
    float volumen= calcularVolumen(area1, altura);
    printf("El perimetro es: \n%.2f\n%.2f\n%.2f\n%.2f\n", per1, per2, per3, per4);
    printf("El area es: \n%.2f\n%.2f\n%.2f\n%.2f\n", area1, area2, area3, area4);
    printf("El area superficial de la piramide: %.2f\n", AS);
    printf("El volumen de la piramide triangular es: %.2f\n", volumen);
    return 0;
}

float calculoDistancia (float x1, float y1, float z1, float x2, float y2, float z2){
    float dist = sqrt(pow(x1-x2,2)+ pow(y1-y2, 2)+ pow(z1-z2, 2));
    return dist;
}

void calcularPerimetro(float puntos [4][3], float *per1, float *per2, float *per3, float *per4, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6){
    *l1= calculoDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2= calculoDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3= calculoDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4= calculoDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5= calculoDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l6= calculoDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   
    *per1= *l1+*l2+*l3;
    *per2= *l2+*l4+*l6;
    *per3= *l3+*l5+*l6;
    *per4= *l1+*l5+*l4;

}

float calcularArea(float per1, float l1, float l2, float l3){
    float s = per1/2;
    float area=sqrt(s*(s-l1)*(s-l2)*(s-l3));
    return area;
}

float calcularAreaSuperficial(float area1, float area2, float area3, float area4){
    float AS=area1+area2+area3+area4;
    return AS;
}
float calcularAltura(float puntos [4][3]){
    float gx=(puntos[0][0]+puntos[1][0]+puntos[2][0])/3;
    float gy=(puntos[0][1]+puntos[1][1]+puntos[2][1])/3;
    float gz=(puntos[0][2]+puntos[1][2]+puntos[2][1])/3;
    float baricentro= gx+gy+gz;
    float altura= sqrt(pow(gx-puntos[3][0], 2)+pow(gy-puntos[3][1], 2)+pow(gz-puntos[3][2], 2));
    return altura;
}

float calcularVolumen(float area1, float altura){
    float volumen= (area1*altura)/3;
    return volumen;
}