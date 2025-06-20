#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265358979323846

#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

void limpar_buffer() { while(getchar()!='\n'); }
void pausar() { printf("\nPressione <ENTER> para retornar ao menu."); limpar_buffer(); }

float ler_num(const char *msg, int positivo) {
    float v; int ok;
    do {
        printf("%s", msg);
        ok = scanf("%f", &v); limpar_buffer();
        if (ok!=1 || (positivo && v<=0))
            printf("Entrada invalida. Digite um numero%s.\n", positivo?" positivo":"");
    } while(ok!=1 || (positivo && v<=0));
    return v;
}

typedef float (*calc_func)(float, float, float);

float area_circulo(float a, float b, float c) { float r=a/2; return PI*r*r; }
float area_losango(float a, float b, float c) { return (a*b)/2; }
float area_paralelogramo(float a, float b, float c) { return a*b; }
float area_trapezio(float a, float b, float c) { return ((a+b)/2)*c; }
float area_triangulo(float a, float b, float c) {
    if(a+b<=c||a+c<=b||b+c<=a) return -1;
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
float vol_esfera(float a, float b, float c) { float r=a/2; return (4.0/3.0)*PI*r*r*r; }
float vol_cone(float a, float b, float c) { float r=a/2; return (PI/3.0)*r*r*b; }
float vol_cilindro(float a, float b, float c) { float r=a/2; return PI*r*r*b; }
float vol_paralelepipedo(float a, float b, float c) { return a*b*c; }

float m2y(float n, float b, float c) { return n*1.09361f; }
float y2m(float n, float b, float c) { return n/1.09361f; }
float cm32in3(float n, float b, float c) { return n/16.387064f; }
float in32cm3(float n, float b, float c) { return n*16.387064f; }
float l2gal(float n, float b, float c) { return n*0.264172f; }
float gal2l(float n, float b, float c) { return n/0.264172f; }
float kg2lb(float n, float b, float c) { return n*2.20462262f; }
float lb2kg(float n, float b, float c) { return n/2.20462262f; }

void desenhar_triangulo(int h) {
    for(int i=1;i<h;i++) {
        for(int j=0;j<h-i;j++) printf(" ");
        printf("/");
        for(int j=0;j<2*(i-1);j++) printf(" ");
        printf("\\\n");
    }
    if(h>=1) {
        printf("/");
        for(int j=0;j<2*(h-1);j++) printf("_");
        printf("\\\n");
    }
}
void desenhar_quadrado(int l) {
    for(int i=0;i<l;i++) {
        for(int j=0;j<l;j++)
            printf((i==0||i==l-1||j==0||j==l-1)?"**":"  ");
        printf("\n");
    }
}
void desenhar_circulo(int r) {
    for(int y=-r;y<=r;y++) {
        for(int x=-r;x<=r;x++) {
            float d=sqrt((x*x*4)+(y*y));
            printf((d>=r*2-1&&d<=r*2+1)?"* ":"  ");
        }
        printf("\n");
    }
}

typedef struct { const char *nome; calc_func func; int args; } ItemMenu;

ItemMenu areas[] = {
    {"Circulo", area_circulo, 1},
    {"Losango", area_losango, 2},
    {"Paralelogramo", area_paralelogramo, 2},
    {"Trapezio", area_trapezio, 3},
    {"Triangulo", area_triangulo, 3}
};
ItemMenu volumes[] = {
    {"Esfera", vol_esfera, 1},
    {"Cone Circular", vol_cone, 2},
    {"Cilindro", vol_cilindro, 2},
    {"Paralelepipedo", vol_paralelepipedo, 3}
};
ItemMenu conversoes[] = {
    {"Metros para Jardas", m2y, 1},
    {"Jardas para Metros", y2m, 1},
    {"Cm3 para Pol3", cm32in3, 1},
    {"Pol3 para Cm3", in32cm3, 1},
    {"Litros para Galoes", l2gal, 1},
    {"Galoes para Litros", gal2l, 1},
    {"Quilogramas para Libras", kg2lb, 1},
    {"Libras para Quilogramas", lb2kg, 1}
};

void titulo(const char *t) {
    for(int i=0;i<60;i++) printf("-");
    printf("\n\n\t*** %s ***\n\n", t);
    for(int i=0;i<60;i++) printf("-");
    printf("\n");
}

void menu_generico(ItemMenu *itens, int n, const char *tipo) {
    int op;
    do {
        system(LIMPAR_TELA);
        titulo(tipo);
        for(int i=0;i<n;i++) printf("%d - %s\n", i+1, itens[i].nome);
        printf("0 - Retornar\nOpcao: ");
        scanf("%d", &op); limpar_buffer();
        if(op>0 && op<=n) {
            float a=0,b=0,c=0, res;
            if(itens[op-1].args>0) a=ler_num("Primeiro valor: ",1);
            if(itens[op-1].args>1) b=ler_num("Segundo valor: ",1);
            if(itens[op-1].args>2) c=ler_num("Terceiro valor: ",1);
            res = itens[op-1].func(a,b,c);
            if(strcmp(tipo,"Area de Figuras Planas")==0 && op==5 && res<0)
                printf("Triangulo invalido.\n");
            else
                printf("Resultado: %.4f\n", res);
            pausar();
        }
    } while(op!=0);
}

void menu_desenho() {
    int op;
    do {
        system(LIMPAR_TELA);
        titulo("Desenhar Figuras");
        printf("1 - Triangulo Isosceles Oco\n2 - Quadrado Oco\n3 - Circulo Oco\n0 - Retornar\nOpcao: ");
        scanf("%d",&op); limpar_buffer();
        if(op==1) {
            int h=ler_num("Altura: ",1);
            desenhar_triangulo(h);
            pausar();
        } else if(op==2) {
            int l=ler_num("Lado: ",1);
            desenhar_quadrado(l);
            pausar();
        } else if(op==3) {
            int r=ler_num("Raio: ",1);
            desenhar_circulo(r);
            pausar();
        }
    } while(op!=0);
}

int main() {
    setlocale(LC_ALL,"");
    int op;
    do {
        system(LIMPAR_TELA);
        titulo("MENU PRINCIPAL");
        printf("1 - Calcular area de figuras planas\n");
        printf("2 - Calcular volume de solidos geometricos\n");
        printf("3 - Conversao de medidas\n");
        printf("4 - Desenhar figuras\n");
        printf("0 - Sair\nOpcao: ");
        scanf("%d",&op); limpar_buffer();
        if(op==1) menu_generico(areas, sizeof(areas)/sizeof(ItemMenu), "Area de Figuras Planas");
        else if(op==2) menu_generico(volumes, sizeof(volumes)/sizeof(ItemMenu), "Volume de Solidos Geometricos");
        else if(op==3) menu_generico(conversoes, sizeof(conversoes)/sizeof(ItemMenu), "Conversao de Medidas");
        else if(op==4) menu_desenho();
    } while(op!=0);
    return 0;
}