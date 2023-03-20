extern  malloc
extern ft_strlen
segment .data
	
segment .bss
	
segment .text
	global ft_strdup
	
	ft_strdup:
		mov rax, 0
		cmp rdi, 0
		jz end

		push rdi

		sub rsp, 0x20 ; shadow space
		call ft_strlen ; rax = len
		add rsp, 0x20

		inc rax
		mov rdi, rax
		push rax

		sub rsp, 0x28 ; shadow space + 16-bytes aligned
		call malloc wrt ..plt
		add rsp, 0x28
		pop rcx
		pop rsi	

		cmp rax, 0
		je end ; malloc failed

		mov rdi, rax
		rep movsb

		end :
			ret