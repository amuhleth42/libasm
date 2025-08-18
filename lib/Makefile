CC = gcc
CFLAGS = -Wall -Werror -Wextra
NASM = nasm
NASM_FLAGS = -f elf64


LIB = libasm.a
EXEC = libasm_tester

ASM_SRCS = ft_strlen.s		\
	   ft_write.s		\
	   ft_strcmp.s		\


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
	rm -f $(ASM_OBJS) $(C_OBJS) $(LIB) $(EXEC)

re:	clean all
