NAME = test

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard ejers_minilibx/*.c)
OBJ = $(SRC:.c=.o)

INCLUDES = -Iincludes -Iminilibx-linux -Iejers_minilibx

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR) #compilar minnilibx si es necesario
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


