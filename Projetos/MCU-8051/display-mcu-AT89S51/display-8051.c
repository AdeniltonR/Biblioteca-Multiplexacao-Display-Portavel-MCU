/*
 * NOME: Adenilton Ribeiro
 * DATA: 19/08/2025
 * PROJETO: Display de 7 Segmentos
 * VERSAO: 1.0.0
 * DESCRICAO: - feat: Fazer um biblioteca para controlar display
 *            - docs:  mikroC PRO for 8051 v3.6.0 - PICSimLab Simulador 0.9.1 - AT89S52
 * LINKS:
*/

// ========================================================================================================
// ---INCLUDE---

#include "display7.h"

// ========================================================================================================
/**
 * @brief Void main
 *
*/
void main(void) {


    //---inicializacao do display---
    display_inicializar();

    while (1) {
        //unsigned char i = 0;
        //for (i = 0; i < 5; i++) {
        //    //---exibe o numero 123 no display---
        //    display_exibir_numero(i);
        //    __ms(80);
        //}

        display_exibir_decimal(12.2);
        __ms(2000);
        //display_exibir_decimal(1.21);
        //__ms(2000);
        //display_exibir_decimal(0.22);
        //__ms(2000);
        //display_exibir_decimal(34.8);
        //__ms(2000);
    }
}