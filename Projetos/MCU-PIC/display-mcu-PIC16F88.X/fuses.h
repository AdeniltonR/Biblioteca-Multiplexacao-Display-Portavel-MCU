/*
 * NOME: Adenilton Ribeiro
 * DATA: 05/02/2025
 * PROJETO: Fuses.h
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Configurações de bits de configuração PIC1688
 *            - docs: MPLAB X IDE v6.20 - Compilador XC8 2.50
 * LINKS: - 
*/

// ========================================================================================================
/**
 * @brief Fuses.h
 * 
 */ 
#ifndef FUSES_H
#define FUSES_H

// Configuracao dos Bits de Configuracao do PIC16F88

// Declaracoes de configuracao no codigo C

// CONFIG1
#pragma config FOSC = XT        // Bits de selecao do oscilador (Oscilador EXTRC; funcao CLKO no pino RA6/OSC2/CLKO)
#pragma config WDTE = OFF       // Bit de ativacao do Watchdog Timer (WDT ativado)
#pragma config PWRTE = OFF      // Bit de ativacao do Power-up Timer (PWRT desativado)
#pragma config MCLRE = OFF      // Bit de selecao da funcao do pino RA5/MCLR/VPP (O pino RA5/MCLR/VPP funciona como MCLR)
#pragma config BOREN = OFF      // Bit de ativacao do Brown-out Reset (BOR ativado)
#pragma config LVP = OFF        // Bit de ativacao da Programacao em Baixa Voltagem (O pino RB3/PGM tem funcao PGM, Programacao em Baixa Voltagem ativada)
#pragma config CPD = OFF        // Bit de protecao de codigo da memoria EEPROM de dados (Protecao de codigo desativada)
#pragma config WRT = OFF        // Bits de ativacao de escrita na memoria Flash (Protecao contra escrita desativada)
#pragma config CCPMX = RB0      // Bit de selecao do pino CCP1 (Funcao CCP1 no pino RB0)
#pragma config CP = OFF         // Bit de protecao de codigo da memoria Flash (Protecao de codigo desativada)

// CONFIG2
#pragma config FCMEN = ON       // Bit de ativacao do Monitor de Falha de Clock (Monitor de Falha de Clock ativado)
#pragma config IESO = ON        // Bit de troca automatica entre oscilador interno e externo (Modo de troca automatica ativado)

// As declaracoes #pragma config devem vir antes dos includes do projeto.
// Use enums do projeto em vez de #define para ON e OFF.

#include <xc.h>

#endif