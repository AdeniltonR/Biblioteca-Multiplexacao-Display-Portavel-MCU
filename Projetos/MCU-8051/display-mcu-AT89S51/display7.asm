
_display_inicializar:
;display7.c,39 :: 		void display_inicializar(void) {
;display7.c,41 :: 		GPIOControlRegister_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g | PIN_pt);
	ANL P2+0, #0
;display7.c,44 :: 		GPIOControlRegister_DIGITS &= ~(PIN_Q1 | PIN_Q2 | PIN_Q3);
	ANL P1+0, #248
;display7.c,47 :: 		display_limpar();
	LCALL _display_limpar+0
;display7.c,48 :: 		}
	RET
; end of _display_inicializar

_display_limpar:
;display7.c,56 :: 		void display_limpar(void) {
;display7.c,58 :: 		PORT_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g | PIN_pt);
	ANL P2+0, #0
;display7.c,61 :: 		PORT_DIGITS &= ~(PIN_Q1 | PIN_Q2 | PIN_Q3);
	ANL P1+0, #248
;display7.c,62 :: 		}
	RET
; end of _display_limpar

_display_exibir_numero:
;display7.c,70 :: 		void display_exibir_numero(int numero) {
;display7.c,71 :: 		unsigned char centenas = 0;
	MOV display_exibir_numero_centenas_L0+0, #0
	MOV display_exibir_numero_dezenas_L0+0, #0
	MOV display_exibir_numero_unidades_L0+0, #0
	MOV display_exibir_numero_i_L0+0, #0
;display7.c,72 :: 		unsigned char dezenas = 0;
;display7.c,73 :: 		unsigned char unidades = 0;
;display7.c,74 :: 		unsigned char i = 0;
;display7.c,77 :: 		display_limpar();
	LCALL _display_limpar+0
;display7.c,80 :: 		if(numero < 0 || numero > 999) {
	CLR C
	MOV A, FARG_display_exibir_numero_numero+0
	SUBB A, #0
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, FARG_display_exibir_numero_numero+1
	XRL A, #128
	SUBB A, R0
	JC L__display_exibir_numero22
	SETB C
	MOV A, FARG_display_exibir_numero_numero+0
	SUBB A, #231
	MOV A, #3
	XRL A, #128
	MOV R0, A
	MOV A, FARG_display_exibir_numero_numero+1
	XRL A, #128
	SUBB A, R0
	JNC L__display_exibir_numero22
	SJMP L_display_exibir_numero2
L__display_exibir_numero22:
;display7.c,81 :: 		return; //---nao exibe numeros fora do intervalo---
	RET
;display7.c,82 :: 		}
L_display_exibir_numero2:
;display7.c,85 :: 		centenas = (numero / 100) % 10;                                    // Obtem o digito das centenas
	MOV R4, #100
	MOV R5, #0
	MOV R0, FARG_display_exibir_numero_numero+0
	MOV R1, FARG_display_exibir_numero_numero+1
	LCALL _Div_16x16_S+0
	MOV R4, #10
	MOV R5, #0
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV display_exibir_numero_centenas_L0+0, 0
;display7.c,86 :: 		dezenas  = (numero / 10) % 10;                                     // Obtem o digito das dezenas
	MOV R4, #10
	MOV R5, #0
	MOV R0, FARG_display_exibir_numero_numero+0
	MOV R1, FARG_display_exibir_numero_numero+1
	LCALL _Div_16x16_S+0
	MOV R4, #10
	MOV R5, #0
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV display_exibir_numero_dezenas_L0+0, 0
;display7.c,87 :: 		unidades = (numero / 1) % 10;                                      // Obtem o digito das unidades
	MOV R4, #10
	MOV R5, #0
	MOV R0, FARG_display_exibir_numero_numero+0
	MOV R1, FARG_display_exibir_numero_numero+1
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV display_exibir_numero_unidades_L0+0, 0
;display7.c,90 :: 		for(i = 0; i < 50; i++) {
	MOV display_exibir_numero_i_L0+0, #0
L_display_exibir_numero3:
	CLR C
	MOV A, display_exibir_numero_i_L0+0
	SUBB A, #50
	JNC L_display_exibir_numero4
;display7.c,92 :: 		display_exibir_digito(centenas, 1);
	MOV FARG_display_exibir_digito_digito+0, display_exibir_numero_centenas_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #1
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,93 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,96 :: 		display_exibir_digito(dezenas, 2);
	MOV FARG_display_exibir_digito_digito+0, display_exibir_numero_dezenas_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #2
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,97 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,100 :: 		display_exibir_digito(unidades, 3);
	MOV FARG_display_exibir_digito_digito+0, display_exibir_numero_unidades_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #3
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,101 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,90 :: 		for(i = 0; i < 50; i++) {
	INC display_exibir_numero_i_L0+0
;display7.c,102 :: 		}
	SJMP L_display_exibir_numero3
L_display_exibir_numero4:
;display7.c,103 :: 		}
	RET
; end of _display_exibir_numero

_display_exibir_digito:
;display7.c,112 :: 		void display_exibir_digito(int digito, int posicao) {
;display7.c,114 :: 		if(digito > 9 || posicao < 1 || posicao > 3) {
	SETB C
	MOV A, FARG_display_exibir_digito_digito+0
	SUBB A, #9
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, FARG_display_exibir_digito_digito+1
	XRL A, #128
	SUBB A, R0
	JNC L__display_exibir_digito23
	CLR C
	MOV A, FARG_display_exibir_digito_posicao+0
	SUBB A, #1
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, FARG_display_exibir_digito_posicao+1
	XRL A, #128
	SUBB A, R0
	JC L__display_exibir_digito23
	SETB C
	MOV A, FARG_display_exibir_digito_posicao+0
	SUBB A, #3
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, FARG_display_exibir_digito_posicao+1
	XRL A, #128
	SUBB A, R0
	JNC L__display_exibir_digito23
	SJMP L_display_exibir_digito8
L__display_exibir_digito23:
;display7.c,115 :: 		return;                                                                // Saia da funcao se os parametros estiverem fora dos limites
	RET
;display7.c,116 :: 		}
L_display_exibir_digito8:
;display7.c,119 :: 		PORT_SEGMENTS &= ~(PIN_a | PIN_b | PIN_c | PIN_d | PIN_e | PIN_f | PIN_g); // Zera os segmentos
	ANL P2+0, #128
;display7.c,122 :: 		switch (posicao) {
	SJMP L_display_exibir_digito9
;display7.c,123 :: 		case 1:
L_display_exibir_digito11:
;display7.c,124 :: 		PORT_DIGITS |=  (PIN_Q1);                                          // Ativa o primeiro digito
	ORL P1+0, #1
;display7.c,125 :: 		PORT_DIGITS &= ~(PIN_Q2 | PIN_Q3);                                 // Desativa os outros
	ANL P1+0, #249
;display7.c,126 :: 		break;
	SJMP L_display_exibir_digito10
;display7.c,127 :: 		case 2:
L_display_exibir_digito12:
;display7.c,128 :: 		PORT_DIGITS |=  (PIN_Q2);                                          // Ativa o segundo digito
	ORL P1+0, #2
;display7.c,129 :: 		PORT_DIGITS &= ~(PIN_Q1 | PIN_Q3);                                 // Desativa os outros
	ANL P1+0, #250
;display7.c,130 :: 		break;
	SJMP L_display_exibir_digito10
;display7.c,131 :: 		case 3:
L_display_exibir_digito13:
;display7.c,132 :: 		PORT_DIGITS |=  (PIN_Q3);                                          // Ativa o terceiro digito
	ORL P1+0, #4
;display7.c,133 :: 		PORT_DIGITS &= ~(PIN_Q1 | PIN_Q2);                                 // Desativa os outros
	ANL P1+0, #252
;display7.c,134 :: 		break;
	SJMP L_display_exibir_digito10
;display7.c,135 :: 		}
L_display_exibir_digito9:
	MOV A, #1
	XRL A, FARG_display_exibir_digito_posicao+0
	JNZ L__display_exibir_digito25
	MOV A, #0
	XRL A, FARG_display_exibir_digito_posicao+1
L__display_exibir_digito25:
	JZ L_display_exibir_digito11
	MOV A, #2
	XRL A, FARG_display_exibir_digito_posicao+0
	JNZ L__display_exibir_digito26
	MOV A, #0
	XRL A, FARG_display_exibir_digito_posicao+1
L__display_exibir_digito26:
	JZ L_display_exibir_digito12
	MOV A, #3
	XRL A, FARG_display_exibir_digito_posicao+0
	JNZ L__display_exibir_digito27
	MOV A, #0
	XRL A, FARG_display_exibir_digito_posicao+1
L__display_exibir_digito27:
	JZ L_display_exibir_digito13
L_display_exibir_digito10:
;display7.c,138 :: 		PORT_SEGMENTS |= segmentos[digito];
	MOV R2, #1
	MOV R1, FARG_display_exibir_digito_digito+1
	MOV A, FARG_display_exibir_digito_digito+0
	INC R2
	SJMP L__display_exibir_digito28
L__display_exibir_digito29:
	CLR C
	RLC A
	XCH A, R1
	RLC A
	XCH A, R1
L__display_exibir_digito28:
	DJNZ R2, L__display_exibir_digito29
	MOV R0, A
	MOV A, #_segmentos+0
	ADD A, R0
	MOV R0, A
	MOV A, @R0
	ORL P2+0, A
;display7.c,139 :: 		}
	RET
; end of _display_exibir_digito

_display_exibir_decimal:
;display7.c,147 :: 		void display_exibir_decimal(float numero) {
;display7.c,148 :: 		unsigned char parte_inteira = 0;
	MOV display_exibir_decimal_parte_inteira_L0+0, #0
	MOV display_exibir_decimal_casas_decimais_L0+0, #0
	MOV display_exibir_decimal_dezenas_L0+0, #0
	MOV display_exibir_decimal_unidades_L0+0, #0
	MOV display_exibir_decimal_primeira_decimal_L0+0, #0
	MOV display_exibir_decimal_segunda_decimal_L0+0, #0
	MOV display_exibir_decimal_i_L0+0, #0
;display7.c,149 :: 		unsigned char casas_decimais = 0;
;display7.c,150 :: 		unsigned char dezenas = 0;
;display7.c,151 :: 		unsigned char unidades = 0;
;display7.c,152 :: 		unsigned char primeira_decimal = 0;
;display7.c,153 :: 		unsigned char segunda_decimal = 0;
;display7.c,154 :: 		unsigned char i = 0;
;display7.c,157 :: 		if (numero < 0.0 || numero >= 100.0) {
	CLR C
	MOV R4, #0
	MOV R5, #0
	MOV R6, #0
	MOV 7, #0
	MOV R0, FARG_display_exibir_decimal_numero+0
	MOV R1, FARG_display_exibir_decimal_numero+1
	MOV R2, FARG_display_exibir_decimal_numero+2
	MOV R3, FARG_display_exibir_decimal_numero+3
	LCALL _Compare_Double+0
	JC L__display_exibir_decimal30
	MOV R0, #0
	SJMP L__display_exibir_decimal31
L__display_exibir_decimal30:
	MOV R0, #1
L__display_exibir_decimal31:
	MOV A, R0
	JNZ L__display_exibir_decimal24
	CLR C
	MOV R4, #0
	MOV R5, #0
	MOV R6, #200
	MOV 7, #66
	MOV R0, FARG_display_exibir_decimal_numero+0
	MOV R1, FARG_display_exibir_decimal_numero+1
	MOV R2, FARG_display_exibir_decimal_numero+2
	MOV R3, FARG_display_exibir_decimal_numero+3
	LCALL _Compare_Double+0
	JNC L__display_exibir_decimal32
	MOV R0, #0
	SJMP L__display_exibir_decimal33
L__display_exibir_decimal32:
	MOV R0, #1
L__display_exibir_decimal33:
	MOV A, R0
	JNZ L__display_exibir_decimal24
	SJMP L_display_exibir_decimal16
L__display_exibir_decimal24:
;display7.c,158 :: 		return;                                                                // Nao exibe numeros fora do intervalo (0.00 a 99.99)
	RET
;display7.c,159 :: 		}
L_display_exibir_decimal16:
;display7.c,162 :: 		parte_inteira =  (int)numero;                                              // Extrai a parte inteira
	MOV R0, FARG_display_exibir_decimal_numero+0
	MOV R1, FARG_display_exibir_decimal_numero+1
	MOV R2, FARG_display_exibir_decimal_numero+2
	MOV R3, FARG_display_exibir_decimal_numero+3
	LCALL _Double2Ints+0
	MOV display_exibir_decimal_parte_inteira_L0+0, 0
;display7.c,163 :: 		casas_decimais = (int)((numero - parte_inteira) * 100 + 0.5);              // Extrai duas casas decimais
	LCALL _Byte2Double+0
	MOV R4, 0
	MOV R5, 1
	MOV R6, 2
	MOV R7, 3
	MOV R0, FARG_display_exibir_decimal_numero+0
	MOV R1, FARG_display_exibir_decimal_numero+1
	MOV R2, FARG_display_exibir_decimal_numero+2
	MOV R3, FARG_display_exibir_decimal_numero+3
	LCALL _Sub_32x32_FP+0
	MOV R4, #0
	MOV R5, #0
	MOV R6, #200
	MOV 7, #66
	LCALL _Mul_32x32_FP+0
	MOV R4, #0
	MOV R5, #0
	MOV R6, #0
	MOV 7, #63
	LCALL _Add_32x32_FP+0
	LCALL _Double2Ints+0
	MOV display_exibir_decimal_casas_decimais_L0+0, 0
;display7.c,165 :: 		dezenas  = (parte_inteira / 10) % 10;                              // Obtem o digito das dezenas (se houver)
	MOV B+0, #10
	MOV A, display_exibir_decimal_parte_inteira_L0+0
	DIV AB
	MOV R0, A
	MOV B+0, #10
	MOV A, R0
	DIV AB
	MOV A, B+0
	MOV R0, A
	MOV display_exibir_decimal_dezenas_L0+0, 0
;display7.c,166 :: 		unidades = (parte_inteira % 10);                                   // Obtem o digito das unidades
	MOV B+0, #10
	MOV A, display_exibir_decimal_parte_inteira_L0+0
	DIV AB
	MOV A, B+0
	MOV R0, A
	MOV display_exibir_decimal_unidades_L0+0, 0
;display7.c,168 :: 		primeira_decimal = casas_decimais / 10;                            // Primeira casa decimal
	MOV B+0, #10
	MOV A, display_exibir_decimal_casas_decimais_L0+0
	DIV AB
	MOV R0, A
	MOV display_exibir_decimal_primeira_decimal_L0+0, 0
;display7.c,169 :: 		segunda_decimal  = casas_decimais % 10;                            // Segunda casa decimal
	MOV B+0, #10
	MOV A, display_exibir_decimal_casas_decimais_L0+0
	DIV AB
	MOV A, B+0
	MOV R0, A
	MOV display_exibir_decimal_segunda_decimal_L0+0, 0
;display7.c,172 :: 		for(i = 0; i < 50; i++) {
	MOV display_exibir_decimal_i_L0+0, #0
L_display_exibir_decimal17:
	CLR C
	MOV A, display_exibir_decimal_i_L0+0
	SUBB A, #50
	JC #3
	LJMP L_display_exibir_decimal18
;display7.c,174 :: 		if (parte_inteira >= 10) {
	CLR C
	MOV A, display_exibir_decimal_parte_inteira_L0+0
	SUBB A, #10
	JC L_display_exibir_decimal20
;display7.c,176 :: 		display_exibir_digito(dezenas, 1);                                 // Exibe as dezenas na posicao 1 (Q1)
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_dezenas_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #1
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,177 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,179 :: 		display_exibir_digito(unidades, 2);                                // Exibe as unidades na posicao 2 (Q2) com o ponto decimal ativado
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_unidades_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #2
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,180 :: 		PORT_SEGMENTS |= PIN_pt;                                           // Liga o ponto decimal no segundo digito (Q2)
	ORL P2+0, #128
;display7.c,181 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,183 :: 		PORT_SEGMENTS &= ~PIN_pt;                                          // Desativa o ponto decimal antes de exibir o proximo digito
	ANL P2+0, #127
;display7.c,185 :: 		display_exibir_digito(primeira_decimal, 3);                        // Exibe a primeira casa decimal na posicao 3 (Q3)
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_primeira_decimal_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #3
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,186 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,188 :: 		} else {
	SJMP L_display_exibir_decimal21
L_display_exibir_decimal20:
;display7.c,189 :: 		display_exibir_digito(unidades, 1);                                // Exibe as unidades na posicao 1 (Q1)
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_unidades_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #1
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,190 :: 		PORT_SEGMENTS |= PIN_pt;                                           // Liga o ponto decimal no segundo digito (Q1)
	ORL P2+0, #128
;display7.c,191 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,193 :: 		PORT_SEGMENTS &= ~PIN_pt;                                          // Desativa o ponto decimal antes de exibir o proximo digito
	ANL P2+0, #127
;display7.c,195 :: 		display_exibir_digito(primeira_decimal, 2);                        // Exibe a primeira casa decimal na posicao 2 (Q2)
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_primeira_decimal_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #2
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,196 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,198 :: 		display_exibir_digito(segunda_decimal, 3);                         // Exibe a segunda casa decimal na posicao 3 (Q3)
	MOV FARG_display_exibir_digito_digito+0, display_exibir_decimal_segunda_decimal_L0+0
	CLR A
	MOV FARG_display_exibir_digito_digito+1, A
	MOV FARG_display_exibir_digito_posicao+0, #3
	MOV FARG_display_exibir_digito_posicao+1, #0
	LCALL _display_exibir_digito+0
;display7.c,199 :: 		__ms(4);
	MOV R6, 7
	MOV R7, 122
	DJNZ R7, 
	DJNZ R6, 
	NOP
;display7.c,200 :: 		}
L_display_exibir_decimal21:
;display7.c,172 :: 		for(i = 0; i < 50; i++) {
	INC display_exibir_decimal_i_L0+0
;display7.c,201 :: 		}
	LJMP L_display_exibir_decimal17
L_display_exibir_decimal18:
;display7.c,204 :: 		display_limpar();
	LCALL _display_limpar+0
;display7.c,205 :: 		}
	RET
; end of _display_exibir_decimal
