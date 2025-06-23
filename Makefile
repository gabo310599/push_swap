NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = push_swap.c \
		src/functions/handle_errors.c \
		src/functions/init_stacks.c \
		src/functions/stack_utils.c \
		src/movements/push.c \
		src/movements/reverse_rotate.c \
		src/movements/rotate.c \
		src/movements/swap.c \
		src/sort/init_nodes_a.c \
		src/sort/init_nodes_b.c \
		src/sort/sort_movements.c \
		src/sort/sort.c \
		src/functions/utils.c \
		

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include -I libft
LIBFT = libft/libft.a
CHECKER = bonus/checker
INCLUDES_BONUS = -I include -I bonus

#-----------------------------------------------------------
# Principal
#-----------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Proyecto compilado correctamente."

#-----------------------------------------------------------
# Compilar archivos fuente
#-----------------------------------------------------------
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  > /dev/null
	@echo "🔧 Compilado: $<"

#-----------------------------------------------------------
# Compilar archivos fuente bonus
#-----------------------------------------------------------
bonus: $(OBJS)
	@$(MAKE) -C libft > /dev/null
	@$(MAKE) -C bonus > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Proyecto compilado con bonus correctamente."

#-----------------------------------------------------------
# Limpiar archivos fuente
#-----------------------------------------------------------
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean > /dev/null
	@$(MAKE) -C bonus clean > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean > /dev/null
	@$(MAKE) -C bonus fclean > /dev/null
	@echo "🧼 Todo limpio."

re: fclean all

.PHONY: all clean fclean re bonus