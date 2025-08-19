
_main:
	MOV SP+0, #128
;display-8051.c,21 :: 		void main(void) {
;display-8051.c,25 :: 		display_inicializar();
	LCALL _display_inicializar+0
;display-8051.c,27 :: 		while (1) {
L_main0:
;display-8051.c,35 :: 		display_exibir_decimal(12.2);
	MOV FARG_display_exibir_decimal_numero+0, #51
	MOV FARG_display_exibir_decimal_numero+1, #51
	MOV FARG_display_exibir_decimal_numero+2, #67
	MOV FARG_display_exibir_decimal_numero+3, #65
	LCALL _display_exibir_decimal+0
;display-8051.c,36 :: 		__ms(2000);
	MOV R5, 13
	MOV R6, 171
	MOV R7, 124
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;display-8051.c,43 :: 		}
	SJMP L_main0
;display-8051.c,44 :: 		}
	SJMP #254
; end of _main
