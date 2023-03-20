segment .data
	
segment .bss
	
segment .text
	global ft_list_size
	
	ft_list_size:

		mov rax, 0

		.loop_count :
			cmp rdi, 0
			je .end
			inc rax
			mov rdi, [rdi + 0x8]
			jmp .loop_count
	
	.end :
		ret
