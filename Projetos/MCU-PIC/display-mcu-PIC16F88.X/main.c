/*
 * NOME: Adenilton Ribeiro
 * DATA: 05/02/2025
 * PROJETO: Display de 7 Segmentos
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Fazer um biblioteca para controlar display
 *            - docs: MPLAB X IDE v6.20 - Compilador XC8 2.50 - PICSimLab Simulador 0.9.1 - PIC16F88
 * LINKS:
*/

// ========================================================================================================
// ---INCLUDE---

#include <xc.h>
#include "display7.h"
#include "fuses.h"

//---defina a frequencia do oscilador---
#define _XTAL_FREQ 8000000  

// ========================================================================================================
//---BIBLIOTECAS AUXILIARES---

// ========================================================================================================
//---MAPEAMENTO DE ESTADO---

// ========================================================================================================
//---MAPEAMENTO DE HARDWARE---

// ========================================================================================================
//---VARIAVEIS GLOBAIS---

// ========================================================================================================
//---PROTOTIPO DA FUNCAO---

// ========================================================================================================
/**
 * @brief Void main
 * 
 */ 
void main(void) {
 
    display_inicializar();
    
    while (1) {
        for (uint8_t i = 0; i < 5; i++) {
            //---exibe o numero 123 no display---
            display_exibir_numero(i);
            __ms(80);
        }
        
        display_exibir_decimal(12.2);
        __ms(2000);
        display_exibir_decimal(1.21);
        __ms(2000);
        display_exibir_decimal(0.22);
        __ms(2000);
        display_exibir_decimal(34.8);
        __ms(2000);
    }
}