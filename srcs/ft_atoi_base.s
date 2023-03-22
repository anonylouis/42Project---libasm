segment .data
	
segment .bss
	
segment .text
	global ft_atoi_base
	
	ft_atoi_base:
		mov rax, 0 ; result
		test rdi, rdi
		jz end
		test rsi, rsi
		jz end
		
		mov r8, 0 ; len_base
		check_base:

			cmp byte [rsi + r8], 0
			je is_valid_base

			cmp byte [rsi + r8], 32
			je end
			cmp byte [rsi + r8], '+'
			je end
			cmp byte [rsi + r8], '-'
			je end
			cmp byte [rsi + r8], 9
			jl check_base_valid_char
			cmp byte [rsi + r8], 13
			jle end

			check_base_valid_char:
			mov dl, byte[rsi + r8]
			mov rcx, r8
			doublon:
				inc rcx
				cmp byte [rsi + rcx], dl
				je end ; invalid base
				cmp byte [rsi + rcx], 0
				jne doublon
			inc r8
			jmp check_base

		is_valid_base:
		cmp r8, 1
		jle end
		mov rcx, 0 ; sign
		
		skip_space:
			cmp [rdi], byte 9
			jl sign
			cmp[rdi], byte 32
			je is_true_space
			cmp[rdi], byte 13
			jg sign
			
			is_true_space:
				inc rdi
				jmp skip_space
		
		sign:
			cmp [rdi], byte '+'
			je is_true_sign
			cmp [rdi], byte '-'
			jne save_sign
			xor rcx, 1 ; count sign

			is_true_sign:
				inc rdi
				jmp sign
		
		save_sign:
		push rcx

		to_int:
			cmp byte[rdi], 0
			je apply_sign
			mov rcx, 0
			mov dl, byte [rdi]
			in_base:
				cmp byte [rsi + rcx], 0
				je apply_sign
				cmp byte [rsi + rcx], dl
				je is_in_base
				inc rcx
				jmp in_base
			
			is_in_base:
			mul r8 ; r8 = len
			add rax, rcx
			inc rdi
			jmp to_int

		apply_sign:
		pop rcx
		cmp rcx, 0
		je end
		neg rax

		end:
			ret