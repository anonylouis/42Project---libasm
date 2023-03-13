
NAME = libasm.a

SRCS = ft_strlen.s
OBJS = ${SRCS:.s=.o}

SRC_TEST = main.c

all : $(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $^

%.o :	%.s
		nasm -f elf64 $<

test :	$(NAME) $(SRC_TEST)
		gcc $(SRC_TEST) $(NAME) -o test

clean :
		rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re : fclean all