segment .data

segment .text
	global ft_list_sort
	
	ft_list_sort:
		mov rdi, [rdi]
		mov r9, rdi ; r9 = base_ptr
		mov rcx, rsi ; rcx = comp fct

		.bubble_sort_extern:
			test rdi, rdi
			jz .end
			mov rsi, r9
			mov rdx, [r9 + 0x8]
			.bubble_sort_intern:
				test rdx, rdx
				jz .bubble_sort_intern_end
				
				push rdi
				push rsi
				push rdx
				push rcx
				push r9

				mov rdi, [rsi]
				mov rsi, [rdx]

				sub rsp, 0x20 ; shadow space

				call rcx

				add rsp, 0x20

				pop r9
				pop rcx
				pop rdx
				pop rsi
				pop rdi

				cmp eax, 0
				jl .no_swap

				mov rax, [rsi]
				mov r8, [rdx]

				mov [rsi], r8
				mov [rdx], rax

				.no_swap:
					mov rsi, rdx
					mov rdx, [rdx + 0x8]
					jmp .bubble_sort_intern

			.bubble_sort_intern_end:
			mov rdi, [rdi + 0x8]
			jmp .bubble_sort_extern

		.end:
			ret

