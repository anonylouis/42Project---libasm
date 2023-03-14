segment .data
segment .bss
segment .text
	global ft_strcmp
	ft_strcmp:

		loop:
			movzx rax, byte[rdi]
			movzx rcx, byte[rsi]
			sub rax, rcx

			cmp byte [rdi], 0
			je end
			cmp byte [rsi], 0
			je end
			cmp al, 0
			jne end

			inc rdi
			inc rsi
			jmp loop
		end:
			ret
