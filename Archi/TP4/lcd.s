	.file	"lcd.c"
	.arch msp430fg4618
	.cpu 430x
	.mpy 16

	.text
	.p2align 1,0
.global	lcd_init
	.type	lcd_init,@function
/***********************
 * Function `lcd_init' 
 ***********************/
lcd_init:
	mov.b	&__P5DIR, r15
	bis.b	#28, r15
	mov.b	r15, &__P5DIR
	mov.b	&__P5SEL, r15
	bis.b	#28, r15
	mov.b	r15, &__P5SEL
	mov.b	#29, &__LCDACTL
	mov.b	#126, &__LCDAPCTL0
	mov.b	#0, &__LCDAPCTL1
	ret
.Lfe1:
	.size	lcd_init,.Lfe1-lcd_init
;; End of function 

	.p2align 1,0
.global	lcd_clear
	.type	lcd_clear,@function
/***********************
 * Function `lcd_clear' 
 ***********************/
lcd_clear:
	mov	#145, r15
.L3:
	mov.b	#0, @r15
	add	#1, r15
	cmp	#165, r15
	jne	.L3
	ret
.Lfe2:
	.size	lcd_clear,.Lfe2-lcd_clear
;; End of function 

	.p2align 1,0
.global	lcd_fill
	.type	lcd_fill,@function
/***********************
 * Function `lcd_fill' 
 ***********************/
lcd_fill:
	mov	#145, r15
.L6:
	mov.b	#llo(-1), @r15
	add	#1, r15
	cmp	#165, r15
	jne	.L6
	ret
.Lfe3:
	.size	lcd_fill,.Lfe3-lcd_fill
;; End of function 

	.p2align 1,0
.global	lcd_display_digit
	.type	lcd_display_digit,@function
/***********************
 * Function `lcd_display_digit' 
 ***********************/
lcd_display_digit:
	add	#146, r15
	cmp	#0, r14
	jeq	.L10
	cmp	#1, r14
	jeq	.L11
	cmp	#2, r14
	jeq	.L12
	cmp	#3, r14
	jeq	.L13
	cmp	#4, r14
	jeq	.L14
	cmp	#5, r14
	jeq	.L15
	cmp	#6, r14
	jeq	.L16
	cmp	#7, r14
	jeq	.L17
	cmp	#8, r14
	jeq	.L18
	cmp	#9, r14
	jeq	.L19
	mov	#0, r14
	jmp	.L9
.L10:
	mov	#95, r14
	jmp	.L9
.L11:
	mov	#6, r14
	jmp	.L9
.L12:
	mov	#107, r14
	jmp	.L9
.L13:
	mov	#47, r14
	jmp	.L9
.L14:
	mov	#54, r14
	jmp	.L9
.L15:
	mov	#61, r14
	jmp	.L9
.L16:
	mov	#125, r14
	jmp	.L9
.L17:
	mov	#7, r14
	jmp	.L9
.L18:
	mov	#127, r14
	jmp	.L9
.L19:
	mov	#63, r14
.L9:
	mov.b	r14, @r15
	ret
.Lfe4:
	.size	lcd_display_digit,.Lfe4-lcd_display_digit
;; End of function 

	.p2align 1,0
.global	lcd_display_number
	.type	lcd_display_number,@function
/***********************
 * Function `lcd_display_number' 
 ***********************/
lcd_display_number:
	pushm	#2, r11
	mov	r15, r11
	mov	#1, r10
.L21:
	mov	#10, r14
	mov	r11, r15
	call	#__umodhi3
	mov	r15, r14
	mov	r10, r15
	call	#lcd_display_digit
	mov	#10, r14
	mov	r11, r15
	call	#__udivhi3
	mov	r15, r11
	add	#1, r10
	cmp	#8, r10
	jne	.L21
	popm	#2, r11
	ret
.Lfe5:
	.size	lcd_display_number,.Lfe5-lcd_display_number
;; End of function 

