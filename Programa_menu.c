#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h> // Para sqrt()

// Define PI para consistencia e precisao
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
const double PI = M_PI;

// Macros para portabilidade
#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear" 
#endif

// Função para limpar o buffer de entrada (substitui fflush(stdin))
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para pausar a tela de forma portavel
void pausar_tela() {
    printf("\n\n Pressione <ENTER> para retornar ao menu.");
#ifdef _WIN32
    getch();
#else
    getchar(); 
#endif
}

// Funcao para ler um inteiro de forma segura
int ler_int(const char *prompt) {
    int valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%d", &valor);
        limpar_buffer_entrada(); 
        if (resultado_scanf != 1) {
            printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
        }
    } while (resultado_scanf != 1);
    return valor;
}

// Função para ler um inteiro positivo de forma segura (usado para altura do desenho)
int ler_int_positivo(const char *prompt) {
    int valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%d", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1) {
            printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
        } else if (valor <= 0) {
            printf("Entrada invalida. O valor deve ser positivo.\n");
            resultado_scanf = 0; // Forca o loop a continuar
        }
    } while (resultado_scanf != 1);
    return valor;
}


// Funcao para ler um float de forma segura
float ler_float(const char *prompt) {
    float valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%f", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
        }
    } while (resultado_scanf != 1);
    return valor;
}

// Funcao para ler um float positivo de forma segura
float ler_float_positivo(const char *prompt) {
    float valor;
    int resultado_scanf;
    do {
        printf("%s", prompt);
        resultado_scanf = scanf("%f", &valor);
        limpar_buffer_entrada();
        if (resultado_scanf != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
        } else if (valor <= 0) {
            printf("Entrada invalida. O valor deve ser positivo.\n");
            resultado_scanf = 0; // For�a o loop a continuar
        }
    } while (resultado_scanf != 1);
    return valor;
}


// --- FUNCOES DE CALCULO ---
float circulo_area(float dia) { float r = dia / 2.0f; return (float)(PI * r * r); }
float losango_area(float D1, float D2) { return (D1 * D2) / 2.0f; }
float paralelogramo_area(float base, float alt) { return base * alt; }
float trapezio_area(float B_maior, float b_menor, float alt) { return ((B_maior + b_menor) / 2.0f) * alt; }
float tri_equi_area(float lado) { return (float)((lado * lado * sqrt(3.0)) / 4.0); }
float triangulo_lados_area(float a, float b, float c) { if (a + b <= c || a + c <= b || b + c <= a) { return -1.0f; } float s = (a + b + c) / 2.0f; return (float)sqrt(s * (s - a) * (s - b) * (s - c)); }
float esfera_vol(float dia) { float r = dia / 2.0f; return (float)((4.0 / 3.0) * PI * r * r * r); }
float cone_vol(float dia_base, float alt) { float r_base = dia_base / 2.0f; return (float)((PI / 3.0) * r_base * r_base * alt); }
float cilindro_vol(float dia_base, float alt) { float r_base = dia_base / 2.0f; return (float)(PI * r_base * r_base * alt); }
float paralelepipedo_vol(float comp, float larg, float alt) { return comp * larg * alt; }

// --- FUNCOES DE CONVERSAO ---
float metros_para_jardas(float num) { return num * 1.09361f; }
float jardas_para_metros(float num) { return num / 1.09361f; }
float cm3_para_pol3(float num) { return num / 16.387064f; }
float pol3_para_cm3(float num) { return num * 16.387064f; }
float litros_para_galoes(float num) { return num * 0.264172f; } 
float galoes_para_litros(float num) { return num / 0.264172f; } 
float kg_para_libras(float num) { return num * 2.20462262f; }
float libras_para_kg(float num) { return num / 2.20462262f; }

// --- FUNCAOO PARA DESENHAR FIGURAS ---
void desenhar_triangulo_isoceles_oco(int altura) {
    int i, j;
    // Parte superior do triangulo (todas as linhas exceto a base)
    for (i = 1; i < altura; i++) {
        // Espacamento lateral para centralizacao
        for (j = 0; j < altura - i; j++) {
            printf(" ");
        }
        // Borda esquerda
        printf("/");
        // Espa�amento interno oco
        for (j = 0; j < 2*(i-1); j++) {
            printf(" ");
        }
        // Borda direita - CORRIGIDO: Removida a condicaoo "if (i > 1)"
        // para que a barra direita seja impressa em todas as linhas do topo
        // (exceto quando i=1 e altura=1, caso em que este loop n�o roda e a base trata)
        printf("\\"); 
        printf("\n");
    }
    // Linha da base
    if (altura >= 1) { 
        // Para altura = 1, o loop superior n�o roda.
        // Esta se��o da base imprimir� "/\" para altura = 1.
        printf("/");
        for (j = 0; j < 2*(altura-1); j++) { 
            printf("_");
        }
        printf("\\\n"); 
    }
}

void titulo (const char *titulo) {
    int i;
    for(i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\n\n\t\t********** %s **********\n\n", titulo);
    for(i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\n");
}

// --- FUNCAO PRINCIPAL ---
void menu_area(int opcao) {
    float a, b, c, area;
    switch (opcao) {
        case 1: // Círculo
            titulo("Área do Círculo");
            a = ler_float_positivo("Diâmetro: ");
            area = circulo_area(a);
            printf("Área: %.2f\n", area);
            break;
        case 2: // Losango
            titulo("Área do Losango");
            a = ler_float_positivo("Diagonal 1: ");
            b = ler_float_positivo("Diagonal 2: ");
            area = losango_area(a, b);
            printf("Área: %.2f\n", area);
            break;
        case 3: // Paralelogramo
            titulo("Área do Paralelogramo");
            a = ler_float_positivo("Base: ");
            b = ler_float_positivo("Altura: ");
            area = paralelogramo_area(a, b);
            printf("Área: %.2f\n", area);
            break;
        case 4: // Trapézio
            titulo("Área do Trapézio");
            a = ler_float_positivo("Base maior: ");
            b = ler_float_positivo("Base menor: ");
            if (b >= a) {
                printf("Erro: Base menor deve ser menor que a base maior.\n");
                break;
            }
            c = ler_float_positivo("Altura: ");
            area = trapezio_area(a, b, c);
            printf("Área: %.2f\n", area);
            break;
        case 5: // Triângulo
            titulo("Área do Triângulo");
            a = ler_float_positivo("Lado A: ");
            b = ler_float_positivo("Lado B: ");
            c = ler_float_positivo("Lado C: ");
            area = triangulo_lados_area(a, b, c);
            if (area < 0) printf("Triângulo inválido.\n");
            else printf("%s >>> Área: %.2f\n", (a == b && b == c) ? "Triângulo Equilátero" :
                        (a == b || b == c || a == c) ? "Triângulo Isósceles" : "Triângulo Escaleno", area);
            break;
        case 0: return;
        default: printf("Opção inválida.\n");
    }
    pausar_tela();
}

// Função para submenu de volumes
void menu_volume(int opcao) {
    float a, b, c, vol;
    switch (opcao) {
        case 1: // Esfera
            titulo("Volume da Esfera");
            a = ler_float_positivo("Diâmetro: ");
            vol = esfera_vol(a);
            printf("Volume: %.2f\n", vol);
            break;
        case 2: // Cone
            titulo("Volume do Cone");
            a = ler_float_positivo("Diâmetro da base: ");
            b = ler_float_positivo("Altura: ");
            vol = cone_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 3: // Cilindro
            titulo("Volume do Cilindro");
            a = ler_float_positivo("Diâmetro: ");
            b = ler_float_positivo("Altura: ");
            vol = cilindro_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 4: // Paralelepípedo
            titulo("Volume do Paralelepípedo");
            a = ler_float_positivo("Comprimento: ");
            b = ler_float_positivo("Largura: ");
            c = ler_float_positivo("Altura: ");
            vol = paralelepipedo_vol(a, b, c);
            printf("Volume: %.2f\n", vol);
            break;
        case 0: return;
        default: printf("Opção inválida.\n");
    }
    pausar_tela();
}

// Função para submenu de conversões
void menu_conversao(int opcao) {
    float num, result;
    const char *unidades[][2] = {
        {"Metros para Jardas", "%.2f m = %.2f yd"},
        {"Jardas para Metros", "%.2f yd = %.2f m"},
        {"Cm³ para Pol³", "%.2f cm³ = %.4f in³"},
        {"Pol³ para Cm³", "%.4f in³ = %.2f cm³"},
        {"Litros para Galões", "%.2f L = %.4f gal"},
        {"Galões para Litros", "%.4f gal = %.2f L"},
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
        printf("Opção inválida.\n");
        pausar_tela();
    }
}

// Função para submenu de desenho
void menu_desenho(int opcao) {
    if (opcao == 1) {
        titulo("Triângulo Isósceles Oco");
        int altura = ler_int_positivo("Altura: ");
        desenhar_triangulo_isoceles_oco(altura);
        pausar_tela();
    } else if (opcao != 0) {
        printf("Opção inválida.\n");
        pausar_tela();
    }
}

// Função genérica para submenu
void submenu(const char *titulo_menu, const char *opcoes[], int num_opcoes, void (*funcao)(int)) {
    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo(titulo_menu);
        for (int i = 0; i < num_opcoes; i++) printf("%s\n", opcoes[i]);
        opcao = ler_int("Opção: ");
        system(LIMPAR_TELA);
        funcao(opcao);
    } while (opcao != 0);
}

// Função principal
int main() {
    setlocale(LC_ALL, ""); // usa a localidade do sistema padrão
    const char *menu_principal[] = {
        "1 - Calcular área de figuras planas",
        "2 - Calcular volume de sólidos geométricos",
        "3 - Conversão de medidas",
        "4 - Desenhar figuras",
        "0 - Sair"
    };
    const char *opcoes_area[] = {
        "1 - Círculo", "2 - Losango", "3 - Paralelogramo",
        "4 - Trapézio", "5 - Triângulo", "0 - Retornar"
    };
    const char *opcoes_volume[] = {
        "1 - Esfera", "2 - Cone Circular", "3 - Cilindro",
        "4 - Paralelepípedo", "0 - Retornar"
    };
    const char *opcoes_conversao[] = {
        "1 - Metros para Jardas", "2 - Jardas para Metros",
        "3 - Cm³ para Pol³", "4 - Pol³ para Cm³",
        "5 - Litros para Galões", "6 - Galões para Litros",
        "7 - Quilogramas para Libras", "8 - Libras para Quilogramas",
        "0 - Retornar"
    };
    const char *opcoes_desenho[] = {
        "1 - Triângulo Isósceles Oco", "0 - Retornar"
    };

    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo("MENU PRINCIPAL");
        for (int i = 0; i < 5; i++) printf("%s\n", menu_principal[i]);
        opcao = ler_int("Opção: ");
        system(LIMPAR_TELA);
        switch (opcao) {
            case 1: submenu("Área de Figuras Planas", opcoes_area, 6, menu_area); break;
            case 2: submenu("Volume de Sólidos Geométricos", opcoes_volume, 5, menu_volume); break;
            case 3: submenu("Conversão de Medidas", opcoes_conversao, 9, menu_conversao); break;
            case 4: submenu("Desenhar Figuras", opcoes_desenho, 2, menu_desenho); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n"); pausar_tela();
        }
    } while (opcao != 0);
    return 0;
}