
NAME        = cube3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
# Adicionei o ponto (.) para buscar headers na raiz onde está o parse.h
CPPFLAGS    = -I. -I$(LIB_DIR)

LIB_DIR     = lib
LIBFT       = $(LIB_DIR)/libft.a

# Fontes que aparecem na sua imagem
SRCS        = main.c open_file.c
OBJS        = $(SRCS:.c=.o)

# Removi a parte do Parse que não existe como pasta na imagem
LDFLAGS     = -L$(LIB_DIR) -lft -lreadline

RM          = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "\033[1;32m[cube3d] Linking: $(NAME)...\033[0m"
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@echo "\033[1;34m[cube3d] Building Libft...\033[0m"
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re