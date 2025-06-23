NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Código fuente del checker
SRCS = checker.c \
		free_everything.c \
		movements_on_stacks.c \
		validate_instructions.c

PUSH_SRCS = ../src/functions/handle_errors.c \
           ../src/functions/init_stacks.c \
           ../src/functions/stack_utils.c \
           ../src/movements/push.c \
           ../src/movements/reverse_rotate.c \
           ../src/movements/rotate.c \
           ../src/movements/swap.c \
           ../src/sort/init_nodes_a.c \
           ../src/sort/init_nodes_b.c \
           ../src/sort/sort_movements.c \
           ../src/sort/sort.c \
           ../src/functions/utils.c

SRCS_ALL = $(SRCS) $(PUSH_SRCS)

OBJS = $(SRCS_ALL:.c=.o)

INCLUDES = -I ../include -I ../libft -I ./include
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ../libft > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Checker compilado correctamente."

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  > /dev/null
	@echo "🔧 Compilado: $<"

clean:
	@rm -f $(OBJS)
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🧼 Todo limpio."
	
re: fclean all

.PHONY: all clean fclean re