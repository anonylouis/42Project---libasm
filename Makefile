
NAME = libasm.a

SRCS_DIR = ./srcs/
SRCS = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s ft_list_size.s

OBJS_DIR = ./objs/
OBJECTS = ${SRCS:.s=.o}
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))

SRC_TEST = main.c

all : $(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $^

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.s
					mkdir -p $(OBJS_DIR)
					nasm -f elf64 -o $@ $< 

test :	$(NAME) $(SRC_TEST)
		gcc $(SRC_TEST) $(NAME) -o test

malloc :	$(NAME) $(SRC_TEST)
			gcc $(SRC_TEST) $(NAME) -o test
			(ulimit -v 2770; ./test ft_strdup)

clean :
		rm -rf $(OBJS_DIR)

fclean :	clean
			rm -f $(NAME)

re : fclean all