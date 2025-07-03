/*
 * NOME: Adenilton Ribeiro
 * DATA: 02/07/2025
 * PROJETO: Display7.h
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Interface para display 7 segmentos
 *            - docs: MPLAB X IDE v6.20 - Compilador XC8 2.46 - PICSimLab Simulador 0.9.1 - PIC16F88
 * LINKS: - 
*/

// ========================================================================================================
/**
 * @brief display7.h
 * 
*/
#ifndef  DISPLAY7_H
#define  DISPLAY7_H

// ========================================================================================================
// ---FREQUENCIA DO OSCILADOR---

#define _XTAL_FREQ 8000000

// ========================================================================================================
// ---BIBLIOTECA---

#include <xc.h>

// ========================================================================================================
//---MAPEAMENTO DE HARDWARE---

//---mapeamento dos pinos para os segmentos do display de 7 segmentos---
#define PIN_a  (1<<0) //RB0
#define PIN_b  (1<<1) //RB1
#define PIN_c  (1<<2) //RB2
#define PIN_d  (1<<3) //RB3
#define PIN_e  (1<<4) //RB4
#define PIN_f  (1<<5) //RB5
#define PIN_g  (1<<6) //RB6
#define PIN_pt (1<<7) //RB7

//---mapeamento dos pinos para os digitos (controle dos 3 displays)---
#define PIN_Q1 (1<<0) //RA0
#define PIN_Q2 (1<<1) //RA1
#define PIN_Q3 (1<<2) //RA2

//---definir os pinos para controle do display. Essas definicoes podem ser ajustadas em cada microcontrolador.
#define PORT_SEGMENTS   PORTB                  // Porta para os segmentos (a, b, c, d, e, f, g, dp)
#define PORT_DIGITS     PORTA                  // Porta para os digitos (Q1, Q2, Q3)

//---define os pinos como SAIDA ou ENTRADA---
#define GPIOControlRegister_SEGMENTS   TRISB   // Registro TRISx para os segmentos como saida
#define GPIOControlRegister_DIGITS     TRISA   // Registro TRISx para os digitos como saida

// ========================================================================================================
//---MACROS---

#define __ms(t) __delay_ms(t)
#define __us(t) __delay_us(t)

// ========================================================================================================
//---PROTOTIPO DA FUNCAO---

void display_inicializar(void);
void display_limpar(void);
void display_exibir_numero(int numero);
void display_exibir_digito(uint8_t digito, uint8_t posicao);
void display_exibir_decimal(float numero);

#endif //DISPLAY7_H