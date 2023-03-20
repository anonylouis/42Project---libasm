extern  malloc

SIZE_T_LIST equ 16 ; sizeof(t_list)

segment .data
	
segment .bss
	
segment .text
	global ft_list_push_front
	
	ft_list_push_front:

		test rdi, rdi
		jz end

		push rdi ; begin_list
		push rsi ; data

		mov rdi, SIZE_T_LIST
		sub rsp, 0x28 ; shadow space + 16-bytes aligned
		call malloc wrt ..plt
		add rsp, 0x28
		pop rsi
		pop rdi
		test rax, rax
		jz end ; malloc failed

		mov [rax], rsi ; set data
		mov rbx, [rdi]
		mov [rax + 0x8], rbx ; set next

		mov [rdi], rax ; new begin

		end:
			ret
