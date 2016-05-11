.section .init9

main:
	/* initialisation de l’ecran */
	call #lcd_init

	/* emballage des arguments */
	MOV #6, R15
	MOV #8, R14

	call #fact

	/* deballage de la valeur de retour de mult
	qu’on re-emballe comme argument pour l’appel suivant */

	call #lcd_display_number

/* infinite loop */
done:
	jmp done

mult:
	MOV #0, R5
	MOV #0, R4
boucle: CMP R4, R14
	JZ fin
	ADD R15, R5
	ADD #1, R4
	JMP boucle
fin:	
	MOV R5, R13


multmat:
	MOV R15, &0x0130
	MOV R14, &0x0138
	MOV &0x013a, R13
	ret

fact:
	CMP #0, R15
	JZ finfact
	PUSH R15
	SUB #1, R15
	call #fact
	MOV R15, R14
	POP R15
	call #multmat
	MOV R13, R15
	ret
	
finfact:
	MOV #1, R15
	
ret
