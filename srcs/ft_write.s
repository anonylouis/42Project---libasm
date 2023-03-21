extern  __errno_location
segment .data
	
segment .bss
	
segment .text
	global ft_write
	
	ft_write:
		mov rax, 1 ; syscall 1 = write
		syscall
		cmp rax, 0
		jge end
		; syscall failed + rax = -errno
		neg rax
		push rax
		sub rsp, 0x20
		call __errno_location wrt ..plt ; rax = &errno
		add rsp, 0x20
		pop rcx
		mov [rax], rcx
		mov rax, -1

		end:
			ret
