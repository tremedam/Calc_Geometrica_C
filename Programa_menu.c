#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>

// Definicao de PI para precisao
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
const double PI = M_PI;

// Macros para limpar tela de forma portavel
#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

// ==================== UTILITARIOS ====================
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar_tela() {
    printf("\n\n Pressione <ENTER> para retornar ao menu.");
#ifdef _WIN32
    getch();
#else
    getchar();
#endif
}

int ler_int(const char *prompt) {
    int valor, resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%d", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1)
            printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
    } while (resultado_scanf != 1);
    return valor;
}

int ler_int_positivo(const char *prompt) {
    int valor, resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%d", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1)
            printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
        else if (valor <= 0) {
            printf("Entrada invalida. O valor deve ser positivo.\n");
            resultado_scanf = 0;
        }
    } while (resultado_scanf != 1);
    return valor;
}

float ler_float(const char *prompt) {
    float valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%f", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1)
            printf("Entrada invalida. Por favor, digite um numero.\n");
    } while (resultado_scanf != 1);
    return valor;
}

float ler_float_positivo(const char *prompt) {
    float valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%f", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1)
            printf("Entrada invalida. Por favor, digite um numero.\n");
        else if (valor <= 0) {
            printf("Entrada invalida. O valor deve ser positivo.\n");
            resultado_scanf = 0;
        }
    } while (resultado_scanf != 1);
    return valor;
}

// ==================== CALCULOS GEOMETRICOS ====================
float circulo_area(float dia) { float r = dia / 2.0f; return (float)(PI * r * r); }
float losango_area(float D1, float D2) { return (D1 * D2) / 2.0f; }
float paralelogramo_area(float base, float alt) { return base * alt; }
float trapezio_area(float B_maior, float b_menor, float alt) { return ((B_maior + b_menor) / 2.0f) * alt; }
float tri_equi_area(float lado) { return (float)((lado * lado * sqrt(3.0)) / 4.0); }
float triangulo_lados_area(float a, float b, float c) {
    if (a + b <= c || a + c <= b || b + c <= a) return -1.0f;
    float s = (a + b + c) / 2.0f;
    return (float)sqrt(s * (s - a) * (s - b) * (s - c));
}

float esfera_vol(float dia) { float r = dia / 2.0f; return (float)((4.0 / 3.0) * PI * r * r * r); }
float cone_vol(float dia_base, float alt) { float r_base = dia_base / 2.0f; return (float)((PI / 3.0) * r_base * r_base * alt); }
float cilindro_vol(float dia_base, float alt) { float r_base = dia_base / 2.0f; return (float)(PI * r_base * r_base * alt); }
float paralelepipedo_vol(float comp, float larg, float alt) { return comp * larg * alt; }

// ==================== CONVERSOES ====================
float metros_para_jardas(float num) { return num * 1.09361f; }
float jardas_para_metros(float num) { return num / 1.09361f; }
float cm3_para_pol3(float num) { return num / 16.387064f; }
float pol3_para_cm3(float num) { return num * 16.387064f; }
float litros_para_galoes(float num) { return num * 0.264172f; }
float galoes_para_litros(float num) { return num / 0.264172f; }
float kg_para_libras(float num) { return num * 2.20462262f; }
float libras_para_kg(float num) { return num / 2.20462262f; }

// ==================== DESENHO ====================
void desenhar_triangulo_isoceles_oco(int altura) {
    int i, j;
    for (i = 1; i < altura; i++) {
        for (j = 0; j < altura - i; j++) printf(" ");
        printf("/");
        for (j = 0; j < 2 * (i - 1); j++) printf(" ");
        printf("\\\n");
    }
    if (altura >= 1) {
        printf("/");
        for (j = 0; j < 2 * (altura - 1); j++) printf("_");
        printf("\\\n");
    }
}

void desenhar_quadrado_oco(int lado) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1)
                printf("**");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void desenhar_circulo_oco(int raio) {
    for (int y = -raio; y <= raio; y++) {
        for (int x = -raio; x <= raio; x++) {
            float distancia = sqrt(x * x + y * y);
            if (distancia >= raio - 0.5 && distancia <= raio + 0.5)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

// ==================== INTERFACE ====================
void titulo(const char *titulo) {
    for (int i = 0; i < 80; i++) printf("-");
    printf("\n\n\t\t********** %s **********\n\n", titulo);
    for (int i = 0; i < 80; i++) printf("-");
    printf("\n");
}

// Submenus
void menu_area(int opcao) {
    float a, b, c, area;
    switch (opcao) {
        case 1:
            titulo("Area do Circulo");
            a = ler_float_positivo("Diametro: ");
            area = circulo_area(a);
            printf("Area: %.2f\n", area);
            break;
        case 2:
            titulo("Area do Losango");
            a = ler_float_positivo("Diagonal 1: ");
            b = ler_float_positivo("Diagonal 2: ");
            area = losango_area(a, b);
            printf("Area: %.2f\n", area);
            break;
        case 3:
            titulo("Area do Paralelogramo");
            a = ler_float_positivo("Base: ");
            b = ler_float_positivo("Altura: ");
            area = paralelogramo_area(a, b);
            printf("Area: %.2f\n", area);
            break;
        case 4:
            titulo("Area do Trapezio");
            a = ler_float_positivo("Base maior: ");
            b = ler_float_positivo("Base menor: ");
            if (b >= a) {
                printf("Erro: Base menor deve ser menor que a base maior.\n");
                break;
            }
            c = ler_float_positivo("Altura: ");
            area = trapezio_area(a, b, c);
            printf("Area: %.2f\n", area);
            break;
        case 5:
            titulo("Area do Triangulo");
            a = ler_float_positivo("Lado A: ");
            b = ler_float_positivo("Lado B: ");
            c = ler_float_positivo("Lado C: ");
            area = triangulo_lados_area(a, b, c);
            if (area < 0)
                printf("Triangulo invalido.\n");
            else
                printf("%s >>> Area: %.2f\n",
                    (a == b && b == c) ? "Triangulo Equilatero" :
                    (a == b || b == c || a == c) ? "Triangulo Isosceles" : "Triangulo Escaleno",
                    area);
            break;
        case 0: return;
        default: printf("Opcao invalida.\n");
    }
    pausar_tela();
}

void menu_volume(int opcao) {
    float a, b, c, vol;
    switch (opcao) {
        case 1:
            titulo("Volume da Esfera");
            a = ler_float_positivo("Diametro: ");
            vol = esfera_vol(a);
            printf("Volume: %.2f\n", vol);
            break;
        case 2:
            titulo("Volume do Cone");
            a = ler_float_positivo("Diametro da base: ");
            b = ler_float_positivo("Altura: ");
            vol = cone_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 3:
            titulo("Volume do Cilindro");
            a = ler_float_positivo("Diametro: ");
            b = ler_float_positivo("Altura: ");
            vol = cilindro_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 4:
            titulo("Volume do Paralelepipedo");
            a = ler_float_positivo("Comprimento: ");
            b = ler_float_positivo("Largura: ");
            c = ler_float_positivo("Altura: ");
            vol = paralelepipedo_vol(a, b, c);
            printf("Volume: %.2f\n", vol);
            break;
        case 0: return;
        default: printf("Opcao invalida.\n");
    }
    pausar_tela();
}

void menu_conversao(int opcao) {
    float num, result;
    const char *unidades[][2] = {
        {"Metros para Jardas", "%.2f m = %.2f yd"},
        {"Jardas para Metros", "%.2f yd = %.2f m"},
        {"Cm3 para Pol3", "%.2f cm3 = %.4f in3"},
        {"Pol3 para Cm3", "%.4f in3 = %.2f cm3"},
        {"Litros para Galoes", "%.2f L = %.4f gal"},
        {"Galoes para Litros", "%.4f gal = %.2f L"},
        {"Quilogramas para Libras", "%.2f kg = %.2f lb"},
        {"Libras para Quilogramas", "%.2f lb = %.2f kg"}
    };
    float (*funcoes[])(float) = {
        metros_para_jardas, jardas_para_metros, cm3_para_pol3, pol3_para_cm3,
        litros_para_galoes, galoes_para_litros, kg_para_libras, libras_para_kg
    };
    if (opcao >= 1 && opcao <= 8) {
        titulo(unidades[opcao-1][0]);
        num = ler_float("Valor: ");
        result = funcoes[opcao-1](num);
        printf(unidades[opcao-1][1], num, result);
        pausar_tela();
    } else if (opcao != 0) {
        printf("Opcao invalida.\n");
        pausar_tela();
    }
}

void menu_desenho(int opcao) {
    if (opcao == 1) {
        titulo("Triangulo Isosceles Oco");
        int altura = ler_int_positivo("Altura: ");
        desenhar_triangulo_isoceles_oco(altura);
        pausar_tela();
    } else if (opcao == 2) {
        titulo("Quadrado");
        int lado = ler_int_positivo("Lado: ");
        desenhar_quadrado_oco(lado);
        pausar_tela();
    } else if (opcao == 3) {
        titulo("Circulo (aproximado)");
        int raio = ler_int_positivo("Raio: ");
        desenhar_circulo_oco(raio);
        pausar_tela();
    } else if (opcao != 0) {
        printf("Opcao invalida.\n");
        pausar_tela();
    }
}

void submenu(const char *titulo_menu, const char *opcoes[], int num_opcoes, void (*funcao)(int)) {
    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo(titulo_menu);
        for (int i = 0; i < num_opcoes; i++) printf("%s\n", opcoes[i]);
        opcao = ler_int("Opcao: ");
        system(LIMPAR_TELA);
        funcao(opcao);
    } while (opcao != 0);
}

// ==================== MAIN ====================
int main() {
    setlocale(LC_ALL, "");
    const char *menu_principal[] = {
        "1 - Calcular area de figuras planas",
        "2 - Calcular volume de solidos geometricos",
        "3 - Conversao de medidas",
        "4 - Desenhar figuras",
        "0 - Sair"
    };
    const char *opcoes_area[] = {
        "1 - Circulo", "2 - Losango", "3 - Paralelogramo",
        "4 - Trapezio", "5 - Triangulo", "0 - Retornar"
    };
    const char *opcoes_volume[] = {
        "1 - Esfera", "2 - Cone Circular", "3 - Cilindro",
        "4 - Paralelepipedo", "0 - Retornar"
    };
    const char *opcoes_conversao[] = {
        "1 - Metros para Jardas", "2 - Jardas para Metros",
        "3 - Cm3 para Pol3", "4 - Pol3 para Cm3",
        "5 - Litros para Galoes", "6 - Galoes para Litros",
        "7 - Quilogramas para Libras", "8 - Libras para Quilogramas",
        "0 - Retornar"
    };
    const char *opcoes_desenho[] = {
        "1 - Triangulo Oco",
        "2 - Quadrado Oco",
        "3 - Circulo Oco",
        "0 - Retornar"
    };

    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo("MENU PRINCIPAL");
        for (int i = 0; i < 5; i++) printf("%s\n", menu_principal[i]);
        opcao = ler_int("Opcao: ");
        system(LIMPAR_TELA);
        switch (opcao) {
            case 1: submenu("Area de Figuras Planas", opcoes_area, 6, menu_area); break;
            case 2: submenu("Volume de Solidos Geometricos", opcoes_volume, 5, menu_volume); break;
            case 3: submenu("Conversao de Medidas", opcoes_conversao, 9, menu_conversao); break;
            case 4: submenu("Desenhar Figuras", opcoes_desenho, 4, menu_desenho); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n"); pausar_tela();
        }
    } while (opcao != 0);
    return 0;
}