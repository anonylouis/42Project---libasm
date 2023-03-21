segment .data

segment .text
	global ft_list_remove_if
	
	ft_list_remove_if:
		test rdi, rdi
		jz .end
		mov rax, [rdi]
		test rax, rax
		jz .end

		mov r8, [rax + 0x8]
		

		.end:
			ret

