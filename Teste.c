#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define LIMPAR_TELA "clear" // Use "cls" para Windows

// Função genérica para ler número (inteiro ou float, positivo ou não)
float ler_numero(const char *prompt, int inteiro, int positivo) {
    float valor;
    int valido;
    do {
        printf("%s", prompt);
        valido = inteiro ? scanf("%d", (int*)&valor) : scanf("%f", &valor);
        while (getchar() != '\n'); // Limpar buffer
        if (valido != 1) printf("Entrada inválida. Digite um número.\n");
        else if (positivo && valor <= 0) {
            printf("Entrada inválida. O valor deve ser positivo.\n");
            valido = 0;
        }
    } while (valido != 1);
    return valor;
}

// Função para pausar a tela
void pausar() {
    printf("\nPressione <ENTER> para continuar.");
    getchar();
}

// Função para exibir título
void titulo(const char *texto) {
    printf("\n=== %s ===\n\n", texto);
}

// Funções de cálculo de área
float circulo_area(float dia) { return PI * pow(dia / 2.0f, 2); }
float losango_area(float d1, float d2) { return (d1 * d2) / 2.0f; }
float paralelogramo_area(float base, float alt) { return base * alt; }
float trapezio_area(float B_maior, float b_menor, float alt) { return ((B_maior + b_menor) / 2.0f) * alt; }
float triangulo_area(float a, float b, float c) {
    if (a + b <= c || a + c <= b || b + c <= a) return -1.0f;
    float s = (a + b + c) / 2.0f;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Funções de cálculo de volume
float esfera_vol(float dia) { return (4.0 / 3.0) * PI * pow(dia / 2.0f, 3); }
float cone_vol(float dia, float alt) { return (PI / 3.0) * pow(dia / 2.0f, 2) * alt; }
float cilindro_vol(float dia, float alt) { return PI * pow(dia / 2.0f, 2) * alt; }
float paralelepipedo_vol(float comp, float larg, float alt) { return comp * larg * alt; }

// Funções de conversão
float metros_para_jardas(float m) { return m * 1.09361f; }
float jardas_para_metros(float yd) { return yd / 1.09361f; }
float cm3_para_pol3(float cm3) { return cm3 / 16.387064f; }
float pol3_para_cm3(float in3) { return in3 * 16.387064f; }
float litros_para_galoes(float l) { return l * 0.264172f; }
float galoes_para_litros(float gal) { return gal / 0.264172f; }
float kg_para_libras(float kg) { return kg * 2.20462262f; }
float libras_para_kg(float lb) { return lb / 2.20462262f; }

// Função para desenhar triângulo isósceles oco
void desenhar_triangulo(int altura) {
    for (int i = 1; i < altura; i++) {
        for (int j = 0; j < altura - i; j++) printf(" ");
        printf("/");
        for (int j = 0; j < 2 * (i - 1); j++) printf(" ");
        printf("\\\n");
    }
    printf("/");
    for (int j = 0; j < 2 * (altura - 1); j++) printf("_");
    printf("\\\n");
}

// Função para submenu de áreas
void menu_area(int opcao) {
    float a, b, c, area;
    switch (opcao) {
        case 1: // Círculo
            titulo("Área do Círculo");
            a = ler_numero("Diâmetro: ", 0, 1);
            area = circulo_area(a);
            printf("Área: %.2f\n", area);
            break;
        case 2: // Losango
            titulo("Área do Losango");
            a = ler_numero("Diagonal 1: ", 0, 1);
            b = ler_numero("Diagonal 2: ", 0, 1);
            area = losango_area(a, b);
            printf("Área: %.2f\n", area);
            break;
        case 3: // Paralelogramo
            titulo("Área do Paralelogramo");
            a = ler_numero("Base: ", 0, 1);
            b = ler_numero("Altura: ", 0, 1);
            area = paralelogramo_area(a, b);
            printf("Área: %.2f\n", area);
            break;
        case 4: // Trapézio
            titulo("Área do Trapézio");
            a = ler_numero("Base maior: ", 0, 1);
            b = ler_numero("Base menor: ", 0, 1);
            if (b >= a) {
                printf("Erro: Base menor deve ser menor que a base maior.\n");
                break;
            }
            c = ler_numero("Altura: ", 0, 1);
            area = trapezio_area(a, b, c);
            printf("Área: %.2f\n", area);
            break;
        case 5: // Triângulo
            titulo("Área do Triângulo");
            a = ler_numero("Lado A: ", 0, 1);
            b = ler_numero("Lado B: ", 0, 1);
            c = ler_numero("Lado C: ", 0, 1);
            area = triangulo_area(a, b, c);
            if (area < 0) printf("Triângulo inválido.\n");
            else printf("%s >>> Área: %.2f\n", (a == b && b == c) ? "Triângulo Equilátero" :
                        (a == b || b == c || a == c) ? "Triângulo Isósceles" : "Triângulo Escaleno", area);
            break;
        case 0: return;
        default: printf("Opção inválida.\n");
    }
    pausar();
}

// Função para submenu de volumes
void menu_volume(int opcao) {
    float a, b, c, vol;
    switch (opcao) {
        case 1: // Esfera
            titulo("Volume da Esfera");
            a = ler_numero("Diâmetro: ", 0, 1);
            vol = esfera_vol(a);
            printf("Volume: %.2f\n", vol);
            break;
        case 2: // Cone
            titulo("Volume do Cone");
            a = ler_numero("Diâmetro da base: ", 0, 1);
            b = ler_numero("Altura: ", 0, 1);
            vol = cone_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 3: // Cilindro
            titulo("Volume do Cilindro");
            a = ler_numero("Diâmetro: ", 0, 1);
            b = ler_numero("Altura: ", 0, 1);
            vol = cilindro_vol(a, b);
            printf("Volume: %.2f\n", vol);
            break;
        case 4: // Paralelepípedo
            titulo("Volume do Paralelepípedo");
            a = ler_numero("Comprimento: ", 0, 1);
            b = ler_numero("Largura: ", 0, 1);
            c = ler_numero("Altura: ", 0, 1);
            vol = paralelepipedo_vol(a, b, c);
            printf("Volume: %.2f\n", vol);
            break;
        case 0: return;
        default: printf("Opção inválida.\n");
    }
    pausar();
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
        num = ler_numero("Valor: ", 0, 0);
        result = funcoes[opcao-1](num);
        printf(unidades[opcao-1][1], num, result);
        pausar();
    } else if (opcao != 0) {
        printf("Opção inválida.\n");
        pausar();
    }
}

// Função para submenu de desenho
void menu_desenho(int opcao) {
    if (opcao == 1) {
        titulo("Triângulo Isósceles Oco");
        int altura = ler_numero("Altura: ", 1, 1);
        desenhar_triangulo(altura);
        pausar();
    } else if (opcao != 0) {
        printf("Opção inválida.\n");
        pausar();
    }
}

// Função genérica para submenu
void submenu(const char *titulo_menu, const char *opcoes[], int num_opcoes, void (*funcao)(int)) {
    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo(titulo_menu);
        for (int i = 0; i < num_opcoes; i++) printf("%s\n", opcoes[i]);
        opcao = ler_numero("Opção: ", 1, 0);
        system(LIMPAR_TELA);
        funcao(opcao);
    } while (opcao != 0);
}

// Função principal
int main() {
    const char *menu_principal[] = {
        "1 - Calcular área de figuras planas",
        "2 - Calcular volume de sólidos geométricos",
        "3 - Conversão de medidas",
        "4 - Desenhar figuras",
        "0 - Sair"
    };
    const char *menu_area[] = {
        "1 - Círculo", "2 - Losango", "3 - Paralelogramo",
        "4 - Trapézio", "5 - Triângulo", "0 - Retornar"
    };
    const char *menu_volume[] = {
        "1 - Esfera", "2 - Cone Circular", "3 - Cilindro",
        "4 - Paralelepípedo", "0 - Retornar"
    };
    const char *menu_conversao[] = {
        "1 - Metros para Jardas", "2 - Jardas para Metros",
        "3 - Cm³ para Pol³", "4 - Pol³ para Cm³",
        "5 - Litros para Galões", "6 - Galões para Litros",
        "7 - Quilogramas para Libras", "8 - Libras para Quilogramas",
        "0 - Retornar"
    };
    const char *menu_desenho[] = {
        "1 - Triângulo Isósceles Oco", "0 - Retornar"
    };

    int opcao;
    do {
        system(LIMPAR_TELA);
        titulo("MENU PRINCIPAL");
        for (int i = 0; i < 5; i++) printf("%s\n", menu_principal[i]);
        opcao = ler_numero("Opção: ", 1, 0);
        system(LIMPAR_TELA);
        switch (opcao) {
            case 1: submenu("Área de Figuras Planas", menu_area, 6, menu_area); break;
            case 2: submenu("Volume de Sólidos Geométricos", menu_volume, 5, menu_volume); break;
            case 3: submenu("Conversão de Medidas", menu_conversao, 9, menu_conversao); break;
            case 4: submenu("Desenhar Figuras", menu_desenho, 2, menu_desenho); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n"); pausar();
        }
    } while (opcao != 0);
    return 0;
}