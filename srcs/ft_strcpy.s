segment .data
segment .bss
segment .text
	global ft_strcpy
	ft_strcpy:
		;rdi = dest
		;rsi = src

		mov rax, rdi ; return value

		loop :
			cmp byte[rsi], 0
			jz end
			movzx rcx, byte[rsi]
			mov [rdi], rcx
			inc rdi
			inc rsi
			jmp loop

		end:
			movzx rcx, byte[rsi]
			mov [rdi], rcx
			ret
