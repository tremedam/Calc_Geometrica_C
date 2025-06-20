# Calculadora Geométrica em C

Este projeto é um programa de terminal em C que permite calcular áreas, volumes, realizar conversões de unidades e desenhar figuras geométricas em ASCII.

## Funcionalidades

- **Cálculo de Áreas de Figuras Planas**
  - Círculo
  - Losango
  - Paralelogramo
  - Trapézio
  - Triângulo (equilátero, isósceles, escaleno)

- **Cálculo de Volumes de Sólidos Geométricos**
  - Esfera
  - Cone circular
  - Cilindro
  - Paralelepípedo

- **Conversão de Unidades**
  - Metros ↔ Jardas
  - Centímetros cúbicos ↔ Polegadas cúbicas
  - Litros ↔ Galões
  - Quilogramas ↔ Libras

- **Desenho de Figuras em ASCII**
  - Triângulo isósceles oco
  - Quadrado oco
  - Círculo oco (aproximado)

## Como Usar

1. Compile o código em C:
    ```sh
    gcc -o calc_geometrica Programa_menu.C -lm
    ```

2. Execute o programa:
    ```sh
    ./calc_geometrica
    ```

3. Siga o menu interativo para escolher a operação desejada.

## Observações

- O programa foi desenvolvido para ser compatível com Windows e Linux.
- Os desenhos em ASCII podem parecer "esticados" dependendo da fonte do terminal. O código tenta compensar isso.
- Não utiliza acentos para garantir compatibilidade máxima em qualquer terminal.

## Créditos

Desenvolvido para fins didáticos em programação C.