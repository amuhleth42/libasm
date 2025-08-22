CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NASM = nasm
NASM_FLAGS = -f elf64 -g -F dwarf


LIB = libasm.a
EXEC = libasm_tester


ASM_SRCS =	ft_strlen.s		\
	   		ft_write.s		\
			ft_strcmp.s		\
			ft_strdup.s		\
			ft_strcpy.s		\

C_SRCS = main.c


ASM_OBJS = $(ASM_SRCS:.s=.o)
C_OBJS = $(C_SRCS:.c=.o)


%.o:	%.s
	$(NASM) $(NASM_FLAGS) $< -o $@

all:	$(LIB) $(EXEC)



$(LIB):	$(ASM_OBJS)
	ar rcs $@ $^

$(EXEC):	$(LIB)
	$(CC) $(CFLAGS) $(C_SRCS) -L. -lasm -o $@

clean:
	rm -f $(ASM_OBJS) $(C_OBJS) $(LIB)

fclean: clean
	rm ${EXEC}

re:	fclean all
