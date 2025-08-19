#line 1 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
#line 1 "g:/meu drive/meus projetos/github/meus-projetos/biblioteca-multiplexacao-display-portavel-mcu/projetos/mcu-8051/display-mcu-at89s51/display7.h"
#line 60 "g:/meu drive/meus projetos/github/meus-projetos/biblioteca-multiplexacao-display-portavel-mcu/projetos/mcu-8051/display-mcu-at89s51/display7.h"
void display_inicializar(void);
void display_limpar(void);
void display_exibir_numero(int numero);
void display_exibir_digito(int digito, int posicao);
void display_exibir_decimal(float numero);
#line 20 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
int segmentos[10] = {
 0b00111111,
 0b00000110,
 0b01011011,
 0b01001111,
 0b01100110,
 0b01101101,
 0b01111101,
 0b00000111,
 0b01111111,
 0b01101111
};
#line 39 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
void display_inicializar(void) {

  P2  &= ~( (1<<0)  |  (1<<1)  |  (1<<2)  |  (1<<3)  |  (1<<4)  |  (1<<5)  |  (1<<6)  |  (1<<7) );


  P1  &= ~( (1<<0)  |  (1<<1)  |  (1<<2) );


 display_limpar();
}
#line 56 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
void display_limpar(void) {

  P2  &= ~( (1<<0)  |  (1<<1)  |  (1<<2)  |  (1<<3)  |  (1<<4)  |  (1<<5)  |  (1<<6)  |  (1<<7) );


  P1  &= ~( (1<<0)  |  (1<<1)  |  (1<<2) );
#line 69 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
void display_exibir_numero(int numero) {
 unsigned char centenas = 0;
 unsigned char dezenas = 0;
 unsigned char unidades = 0;
 unsigned char i = 0;


 display_limpar();


 if(numero < 0 || numero > 999) {
 return;
 }


 centenas = (numero / 100) % 10;
 dezenas = (numero / 10) % 10;
 unidades = (numero / 1) % 10;


 for(i = 0; i < 50; i++) {

 display_exibir_digito(centenas, 1);
  delay_ms(4) ;


 display_exibir_digito(dezenas, 2);
  delay_ms(4) ;


 display_exibir_digito(unidades, 3);
  delay_ms(4) ;
 }
}
#line 111 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
void display_exibir_digito(int digito, int posicao) {

 if(digito > 9 || posicao < 1 || posicao > 3) {
 return;
 }


  P2  &= ~( (1<<0)  |  (1<<1)  |  (1<<2)  |  (1<<3)  |  (1<<4)  |  (1<<5)  |  (1<<6) );

 switch (posicao) {
 case 1:
  P1  |= ( (1<<0) );
  P1  &= ~( (1<<1)  |  (1<<2) );
 break;
 case 2:
  P1  |= ( (1<<1) );
  P1  &= ~( (1<<0)  |  (1<<2) );
 break;
 case 3:
  P1  |= ( (1<<2) );
  P1  &= ~( (1<<0)  |  (1<<1) );
 break;
 }


  P2  |= segmentos[digito];
}
#line 145 "G:/Meu Drive/Meus Projetos/GitHub/Meus-Projetos/Biblioteca-Multiplexacao-Display-Portavel-MCU/Projetos/MCU-8051/display-mcu-AT89S51/display7.c"
void display_exibir_decimal(float numero) {
 unsigned char parte_inteira = 0;
 unsigned char casas_decimais = 0;
 unsigned char dezenas = 0;
 unsigned char unidades = 0;
 unsigned char primeira_decimal = 0;
 unsigned char segunda_decimal = 0;
 unsigned char i = 0;


 if (numero < 0.0 || numero >= 100.0) {
 return;
 }


 parte_inteira = (int)numero;
 casas_decimais = (int)((numero - parte_inteira) * 100 + 0.5);

 dezenas = (parte_inteira / 10) % 10;
 unidades = (parte_inteira % 10);

 primeira_decimal = casas_decimais / 10;
 segunda_decimal = casas_decimais % 10;


 for(i = 0; i < 50; i++) {

 if (parte_inteira >= 10) {

 display_exibir_digito(dezenas, 1);
  delay_ms(4) ;

 display_exibir_digito(unidades, 2);
  P2  |=  (1<<7) ;
  delay_ms(4) ;

  P2  &= ~ (1<<7) ;

 display_exibir_digito(primeira_decimal, 3);
  delay_ms(4) ;

 } else {
 display_exibir_digito(unidades, 1);
  P2  |=  (1<<7) ;
  delay_ms(4) ;

  P2  &= ~ (1<<7) ;

 display_exibir_digito(primeira_decimal, 2);
  delay_ms(4) ;

 display_exibir_digito(segunda_decimal, 3);
  delay_ms(4) ;
 }
 }


 display_limpar();
}
