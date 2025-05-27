#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Para sqrt()

// Define PI para consist�ncia e precis�o
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
const double PI = M_PI;

// Macros para portabilidade
#ifdef _WIN32
#include <conio.h> // Para getch() no Windows
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear" 
#endif

// Fun��o para limpar o buffer de entrada (substitui fflush(stdin))
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fun��o para pausar a tela de forma port�vel
void pausar_tela() {
    printf("\n\n Pressione <ENTER> para retornar ao menu.");
#ifdef _WIN32
    getch();
#else
    getchar(); 
#endif
}

// Fun��o para ler um inteiro de forma segura
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

// Fun��o para ler um inteiro positivo de forma segura (usado para altura do desenho)
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
            resultado_scanf = 0; // For�a o loop a continuar
        }
    } while (resultado_scanf != 1);
    return valor;
}


// Fun��o para ler um float de forma segura
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

// Fun��o para ler um float positivo de forma segura
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


// --- FUN��ES DE C�LCULO ---
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

// --- FUN��ES DE CONVERS�O ---
float metros_para_jardas(float num) { return num * 1.09361f; }
float jardas_para_metros(float num) { return num / 1.09361f; }
float cm3_para_pol3(float num) { return num / 16.387064f; }
float pol3_para_cm3(float num) { return num * 16.387064f; }
float litros_para_galoes(float num) { return num * 0.264172f; } 
float galoes_para_litros(float num) { return num / 0.264172f; } 
float kg_para_libras(float num) { return num * 2.20462262f; }
float libras_para_kg(float num) { return num / 2.20462262f; }

// --- FUN��O PARA DESENHAR FIGURAS ---
void desenhar_triangulo_isoceles_oco(int altura) {
    int i, j;
    
    // Parte superior do tri�ngulo (todas as linhas exceto a base)
    for (i = 1; i < altura; i++) {
        // Espa�amento lateral para centraliza��o
        for (j = 0; j < altura - i; j++) {
            printf(" ");
        }
        
        // Borda esquerda
        printf("/");
        
        // Espa�amento interno oco
        for (j = 0; j < 2*(i-1); j++) {
            printf(" ");
        }
        
        // Borda direita - CORRIGIDO: Removida a condi��o "if (i > 1)"
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
}

// --- FUN��O PRINCIPAL ---
int main(void) {
    int opcao_principal, opcao_submenu;

    do {
        system(LIMPAR_TELA);
        titulo("MENU PRINCIPAL");
        puts("\n\n \tEscolha a opcao desejada:");
        puts("\n\t 1 - Calcular area de figuras planas");
        puts("\t 2 - Calcular volume de solidos geometricos");
        puts("\t 3 - Conversao de medidas");
        puts("\t 4 - Desenhar Figuras"); 
        puts("\t 5 - Sair");             

        opcao_principal = ler_int("\n\t\t\t\tOpcao: ");

        system(LIMPAR_TELA);

        switch (opcao_principal) {
            case 1: // Calcular �rea de figuras planas
                do {
                    system(LIMPAR_TELA);
                    titulo("AREA DE FIGURAS PLANAS");
                    puts("\t\n Escolha a opcao desejada:");
                    puts("\n\t 1 - Circulo");
                    puts("\t 2 - Losango");
                    puts("\t 3 - Paralelogramo");
                    puts("\t 4 - Trapezio");
                    puts("\t 5 - Triangulo");
                    puts("\t 0 - Retornar");

                    opcao_submenu = ler_int("\t\t\t\tOpcao: ");
                    system(LIMPAR_TELA);

                    float dia, area, d1, d2, base, alt, B_maior, b_menor;
                    float ladoA, ladoB, ladoC;

                    switch (opcao_submenu) {
                        case 1:
                            titulo("1. AREA DO CIRCULO");
                            dia = ler_float_positivo("\n\tDigite o diametro do circulo: ");
                            area = circulo_area(dia);
                            printf("\n\n\n\n\n\t>>>  A area do circulo e %.2f", area);
                            pausar_tela();
                            break;
                        case 2:
                            titulo("2. AREA DO LOSANGO");
                            d1 = ler_float_positivo("\n\tDigite a diagonal 1: ");
                            d2 = ler_float_positivo("\n\tDigite a diagonal 2: ");
                            area = losango_area(d1, d2);
                            printf("\n\n\t>>>  A area do losango e %.2f", area);
                            pausar_tela();
                            break;
                        case 3:
                            titulo("3. AREA DO PARALELOGRAMO");
                            base = ler_float_positivo("\n\tDigite a base: ");
                            alt = ler_float_positivo("\n\tDigite a altura: ");
                            area = paralelogramo_area(base, alt);
                            printf("\n\n\t>>> A area do paralelogramo e %.2f", area);
                            pausar_tela();
                            break;
                        case 4:
                            titulo("4. AREA DO TRAPEZIO");
                            B_maior = ler_float_positivo("\n\tDigite a base maior: ");
                            b_menor = ler_float_positivo("\n\tDigite a base menor: ");
                            if (b_menor >= B_maior) {
                                printf("\n\tErro: A base menor deve ser menor que a base maior.");
                                pausar_tela();
                                break;
                            }
                            alt = ler_float_positivo("\n\tDigite a altura: ");
                            area = trapezio_area(B_maior, b_menor, alt);
                            printf("\n\n\t>>> A area do trapezio e: %.2f", area);
                            pausar_tela();
                            break;
                        case 5:
                            printf("\n\n\t\t********** 5. AREA DO TRIANGULO **********");
                            ladoA = ler_float_positivo("\n\tDigite o lado A do triangulo: ");
                            ladoB = ler_float_positivo("\n\tDigite o lado B do triangulo: ");
                            ladoC = ler_float_positivo("\n\tDigite o lado C do triangulo: ");

                            if (ladoA + ladoB <= ladoC || ladoA + ladoC <= ladoB || ladoB + ladoC <= ladoA) {
                                printf("\n\n\n\t\tOs lados fornecidos nao formam um triangulo valido.");
                            } else if (ladoA == ladoB && ladoB == ladoC) { 
                                area = tri_equi_area(ladoA);
                                printf(" \n\n\n\t\tTriangulo Equilatero >>> area: %.2f", area);
                            } else { 
                                area = triangulo_lados_area(ladoA, ladoB, ladoC);
                                if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
                                    printf("\n\n\n\t\tTriangulo Isosceles >>> area: %.2f", area);
                                } else {
                                    printf("\n\n\n\t\tTriangulo Escaleno >>> area: %.2f", area);
                                }
                            }
                            pausar_tela();
                            break;
                        case 0: 
                            break;
                        default:
                            printf("\n\n ******************************* Opcao Invalida ********************************\n");
                            pausar_tela();
                    }
                } while (opcao_submenu != 0);
                break;

            case 2: // Calcular volume de s�lidos geom�tricos
                 do {
                    system(LIMPAR_TELA);
                    titulo("VOLUME DE SOLIDOS GEOMETRICOS");
                    puts("\n\t Escolha a opcao desejada:");
                    puts("\n\t 1 - Esfera");
                    puts("\t 2 - Cone Circular");
                    puts("\t 3 - Cilindro");
                    puts("\t 4 - Paralelepipedo");
                    puts("\t 0 - Retornar");

                    opcao_submenu = ler_int("\n\t\t\t\tOpcao: ");
                    system(LIMPAR_TELA);

                    float dia_vol, vol, alt_vol, comp_vol, larg_vol; 

                    switch (opcao_submenu) {
                        case 1:
                            printf("\n\n\t\t********** 1. VOLUME DA ESFERA **********");
                            dia_vol = ler_float_positivo("\n\tDigite o diametro: ");
                            vol = esfera_vol(dia_vol);
                            printf("\n\n\n\t>>> O volume da esfera e %.2f.", vol);
                            pausar_tela();
                            break;
                        case 2:
                            printf("\n\n\t\t********** 2. VOLUME DO CONE CIRCULAR **********");
                            dia_vol = ler_float_positivo("\n\tDigite o diametro da base: ");
                            alt_vol = ler_float_positivo("\n\tDigite altura: ");
                            vol = cone_vol(dia_vol, alt_vol);
                            printf("\n\t>>> O volume do cone circular e %.2f.", vol);
                            pausar_tela();
                            break;
                        case 3:
                            printf("\n\n\t\t********** 3. VOLUME DO CILINDRO **********");
                            dia_vol = ler_float_positivo("\n\tDigite o diametro: ");
                            alt_vol = ler_float_positivo("\n\tDigite altura: ");
                            vol = cilindro_vol(dia_vol, alt_vol);
                            printf("\n\t>>> O volume do cilindro e %.2f", vol);
                            pausar_tela();
                            break;
                        case 4:
                            printf("\n\n\t\t********** 4. VOLUME DO PARALELEPIPEDO **********");
                            comp_vol = ler_float_positivo("\n\tDigite o comprimento: ");
                            larg_vol = ler_float_positivo("\n\tDigite a largura: ");
                            alt_vol = ler_float_positivo("\n\tDigite a altura: ");
                            vol = paralelepipedo_vol(comp_vol, larg_vol, alt_vol);
                            printf("\n\t>>> O volume do paralelepipedo e %.2f.", vol);
                            pausar_tela();
                            break;
                        case 0: 
                            break;
                        default:
                            printf("\n\n ******************************* Opcao Invalida ********************************\n");
                            pausar_tela();
                    }
                } while (opcao_submenu != 0);
                break;

            case 3: // Convers�o de medidas
                do {
                    system(LIMPAR_TELA);
                    titulo("CONVERSAO DE MEDIDAS");
                    puts("\n\t\t\t Escolha a opcao desejada");
                    puts("\n Converter:\n");
                    printf(" 1 - Metros para Jardas"); printf("\t\t\t\t 5 - Litros para Galoes\n");
                    printf("\n 2 - Jardas para Metros"); printf("\t\t\t\t 6 - Galoes para Litros\n");
                    printf("\n 3 - Centimetros cubicos para Polegadas cubicas"); printf("\t 7 - Quilogramas para Libras\n");
                    printf("\n 4 - Polegadas cubicas para Centimetros cubicos"); printf("\t 8 - Libras para Quilogramas\n");
                    puts("\n\n\t\t 0 - Retornar");

                    opcao_submenu = ler_int("\t\t\t\tOpcao: ");
                    system(LIMPAR_TELA);

                    float num, result;
                    
                    switch (opcao_submenu) {
                        case 1:
                            printf("\n\n\t\t********** 1. METROS EM JARDAS **********");
                            num = ler_float("\n\n\tDigite o valor em metros a ser convertido: ");
                            result = metros_para_jardas(num);
                            printf("\n\n\t\t %.2f m = %.2f yd", num, result);
                            pausar_tela();
                            break;
                        case 2:
                             printf("\n\n\t\t********** 2. JARDAS EM METROS **********");
                            num = ler_float("\n\n\tDigite o valor em jardas a ser convertido: ");
                            result = jardas_para_metros(num);
                            printf("\n\n\t\t %.2f yd = %.2f m", num, result);
                            pausar_tela();
                            break;
                        case 3:
                            printf("\n\n\t********* 3. CENTIMETROS CUBICOS EM POLEGADAS CUBICAS **********");
                            num = ler_float("\n\n\tDigite o valor em centimetros cubicos: ");
                            result = cm3_para_pol3(num);
                            printf("\n\n\t\t %.2f cm3 = %.4f in3", num, result);
                            pausar_tela();
                            break;
                        case 4:
                            printf("\n\n\t********** 4. POLEGADAS CUBICAS EM CENTIMETROS CUBICOS **********");
                            num = ler_float("\n\tDigite o valor em polegadas cubicas: ");
                            result = pol3_para_cm3(num);
                            printf("\n\n\t\t %.4f in3 = %.2f cm3", num, result);
                            pausar_tela();
                            break;
                        case 5:
                            printf("\n\n\t\t********** 5. LITROS EM GALOES **********");
                            num = ler_float("\n\tDigite o valor em litros: ");
                            result = litros_para_galoes(num);
                            printf("\n\n\t\t %.2f L = %.4f gal", num, result);
                            pausar_tela();
                            break;
                        case 6:
                            printf("\n\n\t\t********** 6. GALOES EM LITROS **********");
                            num = ler_float("\n\tDigite o valor em galoes: ");
                            result = galoes_para_litros(num);
                            printf("\n\n\t\t %.4f gal = %.2f L", num, result);
                            pausar_tela();
                            break;
                        case 7:
                            printf("\n\n\t********** 7. QUILOGRAMAS EM LIBRAS **********");
                            num = ler_float("\n\tDigite o valor em quilogramas: ");
                            result = kg_para_libras(num);
                            printf("\n\n\t\t %.2f kg = %.2f lb", num, result);
                            pausar_tela();
                            break;
                        case 8:
                            printf("\n\n\t********* 8. LIBRAS EM QUILOGRAMAS **********");
                            num = ler_float("\n\tDigite o valor em libras: ");
                            result = libras_para_kg(num);
                            printf("\n\n\t\t %.2f lb = %.2f kg", num, result);
                            pausar_tela();
                            break;
                        case 0: 
                            break;
                        default:
                            printf("\n\n ******************************* Opcao Invalida ********************************\n");
                            pausar_tela();
                    }
                } while (opcao_submenu != 0);
                break;

            case 4: // Desenhar Figuras
                do {
                    system(LIMPAR_TELA);
                    titulo("DESENHAR FIGURAS");
                    puts("\t\n Escolha a opcao desejada:");
                    puts("\n\t 1 - Triangulo Isosceles Oco");
                    puts("\t 0 - Retornar");

                    opcao_submenu = ler_int("\t\t\t\tOpcao: ");
                    system(LIMPAR_TELA);

                    int altura_desenho;

                    switch (opcao_submenu) {
                        case 1:
                            printf("\n\n\t\t********** 1. DESENHAR TRIANGULO ISOSCELES OCO **********");
                            altura_desenho = ler_int_positivo("\n\tDigite a altura do triangulo: ");
                            printf("\n"); 
                            desenhar_triangulo_isoceles_oco(altura_desenho);
                            pausar_tela();
                            break;
                        case 0: 
                            break;
                        default:
                            printf("\n\n ******************************* Opcao Invalida ********************************\n");
                            pausar_tela();
                    }
                } while (opcao_submenu != 0);
                break;

            case 5: // Sair
                printf("\n\n\tSaindo do programa...\n\n");
                break;

            default:
                printf("\n\n ******************************* Opcao Invalida ********************************\n");
                printf("Pressione <ENTER> para tentar novamente.");
                getchar(); 
        }

    } while (opcao_principal != 5); 

    return 0;
}
