segment .data

segment .bss

segment .text
	global ft_strlen
	ft_strlen:
		mov rax, 0

		cmp byte [rdi], 0 ;checking first byte
		jz end

		count_letters:
			inc rax
			inc rdi ;checking next byte
			cmp byte [rdi], 0
		jnz count_letters

		end:
			ret
