#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define PI para consistência e precisão
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
const double PI = M_PI;

// Macros para portabilidade
#ifdef _WIN32
#include <conio.h>
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

// Função para limpar o buffer de entrada
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para pausar a tela
void pausar_tela() {
    printf("\n\n Pressione <ENTER> para retornar ao menu.");
#ifdef _WIN32
    getch();
#else
    getchar();
#endif
}

// Função para imprimir linhas de separação
void imprimir_linha(char caractere, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", caractere);
    }
    printf("\n");
}

// Função para exibir títulos com design automático
void exibir_titulo(const char *titulo) {
    imprimir_linha('-', 80);
    printf("\n\t\t********** %s **********\n\n", titulo);
    imprimir_linha('-', 80);
}

// Função genérica para ler números inteiros
int ler_int(const char *prompt) {
    int valor, resultado;
    do {
        printf("%s", prompt);
        resultado = scanf("%d", &valor);
        limpar_buffer_entrada();
        if (resultado != 1) {
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        }
    } while (resultado != 1);
    return valor;
}

// Função genérica para ler números inteiros positivos
int ler_int_positivo(const char *prompt) {
    int valor;
    do {
        valor = ler_int(prompt);
        if (valor <= 0) {
            printf("Entrada inválida. O valor deve ser positivo.\n");
        }
    } while (valor <= 0);
    return valor;
}

// Função genérica para ler números float
float ler_float(const char *prompt) {
    float valor;
    int resultado;
    do {
        printf("%s", prompt);
        resultado = scanf("%f", &valor);
        limpar_buffer_entrada();
        if (resultado != 1) {
            printf("Entrada inválida. Por favor, digite um número.\n");
        }
    } while (resultado != 1);
    return valor;
}

// Função genérica para ler números float positivos
float ler_float_positivo(const char *prompt) {
    float valor;
    do {
        valor = ler_float(prompt);
        if (valor <= 0) {
            printf("Entrada inválida. O valor deve ser positivo.\n");
        }
    } while (valor <= 0);
    return valor;
}

// Funções de cálculo
float circulo_area(float dia) { return (PI * pow(dia / 2.0f, 2)); }
float losango_area(float D1, float D2) { return (D1 * D2) / 2.0f; }
float paralelogramo_area(float base, float alt) { return base * alt; }
float trapezio_area(float B_maior, float b_menor, float alt) { return ((B_maior + b_menor) / 2.0f) * alt; }
float tri_equi_area(float lado) { return (lado * lado * sqrt(3.0)) / 4.0; }
float triangulo_lados_area(float a, float b, float c) {
    float s = (a + b + c) / 2.0f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
float esfera_vol(float dia) { return (4.0 / 3.0) * PI * pow(dia / 2.0f, 3); }
float cone_vol(float dia_base, float alt) { return (PI / 3.0) * pow(dia_base / 2.0f, 2) * alt; }
float cilindro_vol(float dia_base, float alt) { return PI * pow(dia_base / 2.0f, 2) * alt; }
float paralelepipedo_vol(float comp, float larg, float alt) { return comp * larg * alt; }

// Função para desenhar triângulo isósceles oco
void desenhar_triangulo_isoceles_oco(int altura) {
    for (int i = 1; i < altura; i++) {
        for (int j = 0; j < altura - i; j++) printf(" ");
        printf("/");
        for (int j = 0; j < 2 * (i - 1); j++) printf(" ");
        printf("\\\n");
    }
    if (altura >= 1) {
        printf("/");
        for (int j = 0; j < 2 * (altura - 1); j++) printf("_");
        printf("\\\n");
    }
}

// Função principal
int main(void) {
    int opcao_principal, opcao_submenu;

    do {
        system(LIMPAR_TELA);
        exibir_titulo("MENU PRINCIPAL");
        puts("\n\t1 - Calcular área de figuras planas");
        puts("\t2 - Calcular volume de sólidos geométricos");
        puts("\t3 - Conversão de medidas");
        puts("\t4 - Desenhar Figuras");
        puts("\t5 - Sair");

        opcao_principal = ler_int("\n\tOpção: ");

        switch (opcao_principal) {
            case 1:
                // Submenu para cálculo de áreas
                break;
            case 2:
                // Submenu para cálculo de volumes
                break;
            case 3:
                // Submenu para conversão de medidas
                break;
            case 4:
                // Submenu para desenho de figuras
                break;
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                pausar_tela();
        }
    } while (opcao_principal != 5);

    return 0;
}