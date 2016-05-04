.section .init9
main:
	call #lcd_init
	push #100
	push #200
	push #300
	push #400
	push #500
	push #600
	push #700
	push #800
	push #900
	push #1000
	mov #10, r15
	call #sum_many
	add #20, r1 /* stack cleanup */
	/* return value R15 becomes first argument of next call */
	call #lcd_display_number

loop:
	jmp loop

sum_many:
	mov #0, R14
	mov R15, R12
	ADD #1, R12
	mov #0, R15
	POP R10

boucle:	
	ADD #1, R14
	CMP R14, R12
	JZ fin
	POP R13
	ADD R13, R15
	JMP boucle

fin:	ADD #4, R10
	PUSH R10

ret
	
