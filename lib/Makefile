CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NASM = nasm
NASM_FLAGS = -f elf64 -g -F dwarf


LIB = libasm.a
LIB_BONUS = libasm.a
EXEC = libasm_tester
EXEC_BONUS = libasm_tester_bonus


ASM_SRCS =	ft_strlen.s		\
	   		ft_write.s		\
			ft_strcmp.s		\
			ft_strdup.s		\
			ft_strcpy.s		\

ASM_SRCS_BONUS =	ft_list_sort.s			\
					ft_list_push_front.s	\
					ft_create_elem.s		\
					ft_list_size.s			\


C_SRCS = main.c

C_SRCS_BONUS = main_bonus.c


ASM_OBJS = $(ASM_SRCS:.s=.o)
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS_BONUS = $(ASM_SRCS_BONUS:.s=.o)
C_OBJS_BONUS = $(C_SRCS_BONUS:.c=.o)


%.o:	%.s
	$(NASM) $(NASM_FLAGS) $< -o $@

all:	$(LIB) $(EXEC)

bonus:	$(LIB_BONUS) $(EXEC_BONUS)


$(LIB):	$(ASM_OBJS)
	ar rcs $@ $^

$(LIB_BONUS):	$(ASM_OBJS_BONUS)
	ar rcs $@ $^

$(EXEC):	$(LIB)
	$(CC) $(CFLAGS) $(C_SRCS) -L. -lasm -o $@

$(EXEC_BONUS):	$(LIB_BONUS)
	$(CC) $(CFLAGS) $(C_SRCS_BONUS) -L. -lasm -o $@

clean:
	rm -f $(ASM_OBJS) $(C_OBJS) $(LIB) $(EXEC)

re:	clean all
