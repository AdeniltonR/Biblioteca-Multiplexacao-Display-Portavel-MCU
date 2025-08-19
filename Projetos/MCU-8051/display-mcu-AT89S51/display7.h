/*
 * NOME: Adenilton Ribeiro
 * DATA: 19/08/2025
 * PROJETO: Display7.h
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Interface para display 7 segmentos
 *            - docs:  mikroC PRO for 8051 v3.6.0 - PICSimLab Simulador 0.9.1 - AT89S52
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

//---defina a frequencia do oscilador---
//10MHZ

// ========================================================================================================
//---MAPEAMENTO DE HARDWARE---

//---mapeamento dos pinos para os segmentos do display de 7 segmentos---
#define PIN_a  (1<<0) //P2.0
#define PIN_b  (1<<1) //P2.1
#define PIN_c  (1<<2) //P2.2
#define PIN_d  (1<<3) //P2.3
#define PIN_e  (1<<4) //P2.4
#define PIN_f  (1<<5) //P2.5
#define PIN_g  (1<<6) //P2.6
#define PIN_pt (1<<7) //P2.7

//---mapeamento dos pinos para os digitos (controle dos 3 displays)---
#define PIN_Q1 (1<<0) //P1.0
#define PIN_Q2 (1<<1) //P1.1
#define PIN_Q3 (1<<2) //P1.2

//---definir os pinos para controle do display. Essas definicoes podem ser ajustadas em cada microcontrolador.
#define PORT_SEGMENTS   P2                  // Porta para os segmentos (a, b, c, d, e, f, g, dp)
#define PORT_DIGITS     P1                  // Porta para os digitos (Q1, Q2, Q3)

//---define os pinos como SAIDA ou ENTRADA---
#define GPIOControlRegister_SEGMENTS   P2   // Registro TRISx para os segmentos como saida
#define GPIOControlRegister_DIGITS     P1   // Registro TRISx para os digitos como saida

// ========================================================================================================
//---MACROS---

#define __ms(t) delay_ms(t)
#define __us(t) delay_us(t)

// ========================================================================================================
//---PROTOTIPO DA FUNCAO---

void display_inicializar(void);
void display_limpar(void);
void display_exibir_numero(int numero);
void display_exibir_digito(int digito, int posicao);
void display_exibir_decimal(float numero);

#endif //DISPLAY7_H