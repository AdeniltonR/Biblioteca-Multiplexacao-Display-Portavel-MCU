/*
 * NOME: Adenilton Ribeiro
 * DATA: 05/02/2025
 * PROJETO: Display7.c
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Configuracao da biblioteca para MCU.
 *            - docs: MPLAB X IDE v6.20 - Compilador XC8 2.46 - PICSimLab Simulador 0.9.1 - PIC16F88
 * LINKS:
*/

// ========================================================================================================
// ---BIBLIOTECA---

#include "display7.h"

// ========================================================================================================
//---VARIAVEIS GLOBAIS---

//---define o padrao dos segmentos para os digitos de 0 a 9---
uint8_t segmentos[10] = {
    0b00111111,    // 0
    0b00000110,    // 1
    0b01011011,    // 2
    0b01001111,    // 3
    0b01100110,    // 4
    0b01101101,    // 5
    0b01111101,    // 6
    0b00000111,    // 7
    0b01111111,    // 8
    0b01101111     // 9
};
    
// ========================================================================================================
/**
 * @brief Inicializa o display de 7 segmentos
 * 
 * @note Configura os pinos e prepara o display para operacao
 */
void display_inicializar(void) {
    //---configura os pinos dos segmentos como saida---
    GPIOControlRegister_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g | PIN_pt);
    
    //---configura os pinos de controle (Q1, Q2, Q3) como saida---
    GPIOControlRegister_DIGITS &= ~(PIN_Q1 | PIN_Q2 | PIN_Q3);

    //---limpa o display inicialmente---
    display_limpar();
    
}

// ========================================================================================================
/**
 * @brief Limpa todos os displays, apagando os segmentos
 * 
 * @note Remove qualquer dado exibido
 */
void display_limpar(void) {
    //---desliga todos os segmentos (a, b, c, d, e, f, g, pt)---
    PORT_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g | PIN_pt);
    
    //---desativa todos os digitos (Q1, Q2, Q3)---
    PORT_DIGITS &= ~(PIN_Q1 | PIN_Q2 | PIN_Q3);
}

// ========================================================================================================
/**
 * @brief Exibe um numero inteiro no display de 7 segmentos
 * 
 * @param numero O numero inteiro a ser exibido
 */
void display_exibir_numero(int numero) {
    //---limpa o display antes de exibir o novo numero---
    display_limpar();
    
    //---verifica se o numero esta dentro do intervalo permitido---
    if(numero < 0 || numero > 999) {
        return; //---nao exibe numeros fora do intervalo---
    }
    
    //---extrai os digitos das unidades, dezenas e centenas---
    uint8_t centenas = (numero / 100) % 10;                                    // Obtem o digito das centenas
    uint8_t dezenas  = (numero / 10) % 10;                                     // Obtem o digito das dezenas
    uint8_t unidades = (numero / 1) % 10;                                      // Obtem o digito das unidades
    
    //---ciclo para multiplexacao (ajuste o valor de 50 conforme necessario)---
    for (uint8_t i = 0; i < 50; i++) { 
        //---exibe centenas na posicao 1 (Q1)---
        display_exibir_digito(centenas, 1);
        __ms(4);  

        //---exibe dezenas na posicao 2 (Q2)---
        display_exibir_digito(dezenas, 2);
        __ms(4);  

        //---exibe unidades na posicao 3 (Q3)---
        display_exibir_digito(unidades, 3);
        __ms(4); 
    }
}

// ========================================================================================================
/**
 * @brief Exibe um digito em uma posicao especifica no display
 * 
 * @param digito O digito a ser exibido (0-9)
 * @param posicao A posicao do display (1, 2 ou 3)
 */
void display_exibir_digito(uint8_t digito, uint8_t posicao) {
    //---verifica se o digito esta dentro do intervalo valido---
    if(digito > 9 || posicao < 1 || posicao > 3) {
        return;                                                                // Saia da funcao se os parametros estiverem fora dos limites
    }
    //---limpa os pinos do display---
    PORT_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g); // Zera os segmentos

    //---ativa o digito correspondente---
    switch (posicao) {
        case 1:
            PORT_DIGITS &= ~(PIN_Q2 | PIN_Q3);                                 // Desativa os outros
            PORT_DIGITS |=  (PIN_Q1);                                          // Ativa o primeiro digito
            break;
        case 2:
            PORT_DIGITS &= ~(PIN_Q1 | PIN_Q3);                                 // Desativa os outros
            PORT_DIGITS |=  (PIN_Q2);                                          // Ativa o segundo digito
            break;
        case 3:
            PORT_DIGITS &= ~(PIN_Q1 | PIN_Q2);                                 // Desativa os outros
            PORT_DIGITS |=  (PIN_Q3);                                          // Ativa o terceiro digito
            break;
    }

    //---atualiza os segmentos do display com o digito correspondente---
    PORT_SEGMENTS |= segmentos[digito];
}

// ========================================================================================================
/**
 * @brief Exibe um numero decimal no display de 7 segmentos
 * 
 * @param numero O numero decimal a ser exibido (max. 2 inteiros e 1 decimal)
 */
void display_exibir_decimal(float numero) {
    //---limita o numero ao intervalo exibivel---
    if (numero < 0.0 || numero >= 100.0) {
        return;                                                                // Nao exibe numeros fora do intervalo (0.00 a 99.99)
    }

    //---separa a parte inteira e as casas decimais---
    uint8_t parte_inteira =  (uint8_t)numero;                                  // Extrai a parte inteira
    uint8_t casas_decimais = (uint8_t)((numero - parte_inteira) * 100 + 0.5);  // Extrai duas casas decimais

    uint8_t dezenas  = (parte_inteira / 10) % 10;                              // Obtem o digito das dezenas (se houver)
    uint8_t unidades = (parte_inteira % 10);                                   // Obtem o digito das unidades

    uint8_t primeira_decimal = casas_decimais / 10;                            // Primeira casa decimal
    uint8_t segunda_decimal  = casas_decimais % 10;                            // Segunda casa decimal

    //---loop de multiplexacao---
    for (uint8_t i = 0; i < 50; i++) {
        //---caso de numeros >= 10 (ex: 10.2)---
        if (parte_inteira >= 10) {
            
            display_exibir_digito(dezenas, 1);                                 // Exibe as dezenas na posicao 1 (Q1)
            __ms(4);

            display_exibir_digito(unidades, 2);                                // Exibe as unidades na posicao 2 (Q2) com o ponto decimal ativado
            __ms(3);
            PORT_SEGMENTS |= PIN_pt;                                           // Liga o ponto decimal no segundo digito (Q2)
            __ms(2);

            PORT_SEGMENTS &= ~PIN_pt;                                          // Desativa o ponto decimal antes de exibir o proximo digito

            display_exibir_digito(primeira_decimal, 3);                        // Exibe a primeira casa decimal na posicao 3 (Q3)
            __ms(4);
        //---caso de numeros < 10 (ex: 1.21)---
        } else {                                                               
            display_exibir_digito(unidades, 1);                                // Exibe as unidades na posicao 1 (Q1)
            PORT_SEGMENTS |= PIN_pt;                                           // Liga o ponto decimal no segundo digito (Q1)
            __ms(4);
            
            PORT_SEGMENTS &= ~PIN_pt;                                          // Desativa o ponto decimal antes de exibir o proximo digito

            display_exibir_digito(primeira_decimal, 2);                        // Exibe a primeira casa decimal na posicao 2 (Q2)
            __ms(4);

            display_exibir_digito(segunda_decimal, 3);                         // Exibe a segunda casa decimal na posicao 3 (Q3)
            __ms(4);
        }
    }

    //---limpa o display no final---
    display_limpar();
}
