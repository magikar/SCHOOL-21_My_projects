section .text

global _ft_strcmp

_ft_strcmp:
		xor		rax, rax
		xor		rdx, rdx
		cmp		rsi, byte 0
		je		.return
		cmp		rdi, byte 0
		je		.return
.while:
		movzx	ax, [rdi]
		movzx	dx, [rsi]
		sub		rax, rdx
		cmp		ax, 0
		jg		.plus
		jl		.minus
		cmp		[rdi], byte 0
		je		.return
		inc		rdi
		inc 	rsi
		jmp		.while

.minus:
		mov		rax, -1
		jmp		.return

.plus:
		mov		rax, 1

.return:
		ret