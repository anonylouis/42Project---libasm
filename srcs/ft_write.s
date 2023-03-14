extern  __errno_location
segment .data
	
segment .bss
	
segment .text
	global ft_write
	
	ft_write:
		mov rax, 1
		syscall
		cmp rax, 0
		jge end
		; syscall failed + rax = -errno
		neg rax
		mov rbx, rax
		call __errno_location wrt ..plt ; rax = &errno
		mov [rax], rbx
		mov rax, -1

		end:
			ret
