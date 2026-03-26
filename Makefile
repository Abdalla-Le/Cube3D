
NAME        = cube3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
CPPFLAGS    = -I. -I$(LIB_DIR)

LIB_DIR     = lib
LIBFT       = $(LIB_DIR)/libft.a

SRCS        = main.c stdin_parse.c parse_map.c parse_file.c path_way.c lst_moves.c parse_file_utils.c validate_wall.c path_way_utils.c free_all.c parse.c
OBJS        = $(SRCS:.c=.o)

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