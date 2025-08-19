#line 1 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display-8051.c"
#line 1 "g:/meu drive/meus projetos/github/meus-projetos/biblioteca-multiplexacao-display-portavel-mcu/projetos/mcu-8051/display-mcu-at89s51/display7.h"
#line 60 "g:/meu drive/meus projetos/github/meus-projetos/biblioteca-multiplexacao-display-portavel-mcu/projetos/mcu-8051/display-mcu-at89s51/display7.h"
void display_inicializar(void);
void display_limpar(void);
void display_exibir_numero(int numero);
void display_exibir_digito(int digito, int posicao);
void display_exibir_decimal(float numero);
#line 21 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display-8051.c"
void main(void) {



 display_inicializar();

 while (1) {







 display_exibir_decimal(12.2);
  delay_ms(2000) ;






 }
}
