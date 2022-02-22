section .text

global _ft_strcpy

_ft_strcpy:
		mov rax, rdi
		cmp rsi, byte 0				; проверка указателя (вроде src != NULL)
		je	.return
		cmp rdi, byte 0				; проверка указателя (вроде dest != NULL)
		je	.return
.while:
		cmp [rsi], byte 0
		je	.return
		mov cl, [rsi]				; копируем символ в однобайтовый регистр (buf/tmp)
		mov [rdi], cl				; копируем символ из регистра в строку dest
		inc rdi						; инкрементируем адрес (смещаем указатель на след. символ строки)
		inc rsi
		jmp .while					; повторить

.return:
		mov [rdi], byte 0
		ret