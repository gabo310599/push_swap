NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = push_swap.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include -I libft
LIBFT = libft/libft.a

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
# Compilar archivos fuente
#-----------------------------------------------------------
clean:
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean > /dev/null
	@echo "🧼 Todo limpio."

re: fclean all

.PHONY: all clean fclean re bonus