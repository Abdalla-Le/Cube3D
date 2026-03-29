NAME    = cub3D

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_INC = -I$(MLX_DIR)
MLX_LNK = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INC_DIR = ./includes
SRC_DIR = ./src

SRCS    = $(SRC_DIR)/main.c \
          $(SRC_DIR)/hooks.c \
          $(SRC_DIR)/render.c \
          $(SRC_DIR)/draw.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $(NAME)

%.o: %.c $(INC_DIR)/cub3d.h
	$(CC) $(CFLAGS) $(MLX_INC) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all