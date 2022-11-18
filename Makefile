NAME = so_long.a
SRC = so_long.c
OBJ = $(SRC:%.c=%.o)
CC = gcc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ) mlx
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long
mlx: 
	make -C mlx
.PHONY: mlx