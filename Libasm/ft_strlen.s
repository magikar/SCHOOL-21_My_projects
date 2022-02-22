section .text

global _ft_strlen				; global _ft_strlen

_ft_strlen:						; _ft_strlen
		xor rax, rax			; счетчик
		cmp	rdi, byte 0			; сравнение с символом '\0'
		je	.return			; прыжок на метку, если выражение выше == 0

.while:	
		cmp [rdi], byte 0
		je	.return
		inc rax				; инкрементация счетчика
		inc rdi				; инкрементация адреса строки
		jmp .while

.return:
		ret