.section .init9

main:
	/*initialisation de la diode rouge*/
	mov.b #2, &49
	mov #20000, R11
	clrz

	

loop:	
	/*eteindre*/
	mov.b #0, &50
	mov #0,  R10
tempo1:
	add #1, R10
	cmp R11, R10
	jne tempo1


	/*allumer*/
	mov.b #2, &50
	mov #0,  R10
tempo2:
	add #1, R10
	cmp R11, R10
	jne tempo2

	jmp loop
