extern free
segment .data

segment .text
	global ft_list_remove_if
	
	ft_list_remove_if:
		test rdi, rdi
		jz .end
		test rdx, rdx
		jz .end
		mov r8, [rdi]
		test r8, r8
		jz .end

		.remove_corps:
			mov r9, [r8 + 0x8]
			test r9, r9
			jz .remove_base

			push rdi ; base_ptr
			push rsi ; data_ref
			push rdx ; cmp function
			push rcx ; free function
			push r8 ; t_list *
			push r9  ; rax->next

			mov rdi, [r9]

			sub rsp, 0x8 ; 16 bytes-aligned
			sub rsp, 0x20 ; shadow space 
			call rdx
			add rsp, 0x20
			add rsp, 0x8
			
			pop r9
			pop r8
			pop rcx
			pop rdx
			pop rsi
			pop rdi

			test eax, eax
			jnz .no_remove
			;remove case :
			mov rax, [r9 + 0x8]
			mov [r8 + 0x8], rax

			push rdi ; base_ptr
			push rsi ; data_ref
			push rdx ; cmp function
			push rcx ; free function
			push r8 ; t_list *
			push r9 ; r8->next

			test rcx, rcx
			jz .no_free_fct_corps
			mov rdi, [r9]
			sub rsp, 0x20 ; shadow space
			sub rsp, 0x8 ; 16 bytes-aligned
			call rcx
			add rsp, 0x8
			add rsp, 0x20

			.no_free_fct_corps :
				pop rdi ; MASTERCLASS
				sub rsp, 0x20 ; shadow space 
				call free wrt ..plt
				add rsp, 0x20

				pop r8
				pop rcx
				pop rdx
				pop rsi
				pop rdi
				jmp .remove_corps

			.no_remove:
				mov r8, r9
				jmp .remove_corps
		
		.remove_base:
			mov r8, [rdi]

			push rdi ; base_ptr
			push rsi ; data_ref
			push rdx ; cmp function
			push rcx ; free function
			push r8  ; t_list *base
			
			mov rdi, [r8]

			sub rsp, 0x20 ; shadow space 
			call rdx
			add rsp, 0x20

			pop r8
			pop rcx
			pop rdx
			pop rsi
			pop rdi

			test eax, eax
			jnz .end

			mov r9, [r8+0x8]
			mov [rdi], r9

			push r8
			test rcx, rcx
			jz .no_free_fct_base
			mov rdi, [r8]
			sub rsp, 0x20 ; shadow space 
			call rcx
			add rsp, 0x20

			.no_free_fct_base:
				pop rdi ; MASTERCLASS
				sub rsp, 0x20 ; shadow space
				sub rsp, 0x8 ; 16 bytes-aligned
				call free wrt ..plt
				add rsp, 0x8
				add rsp, 0x20

		.end:
			ret
