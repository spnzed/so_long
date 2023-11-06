NAME 	= so_long

CFLAGS = -Wall -Werror -Wextra

SRC = 	srcs/comprove_ber/check_ber.c \
		srcs/comprove_ber/check_map.c \
		srcs/comprove_ber/check_way.c \
		srcs/comprove_ber/coins_exits.c \
		srcs/game_engine/checkprepare.c \
		srcs/game_engine/move_hero.c \
		srcs/graphics_module/map_to_screen.c \
		srcs/graphics_module/put_sprite.c \
		srcs/graphics_module/refresh_sprite.c \
		srcs/so_long.c \


OBJ 	= ${SRC:.c=.o}

ARCHIVES	= include/libft/libft.a include/mlx/libmlx.a

RM 		= rm -f

HEADER	= include/so_long.h

all:
	@make --no-print-directory -C include/libft
	@make --no-print-directory -C include/mlx
	@make --no-print-directory ${NAME}

%.o: %.c	${HEADER} ${ARCHIVES}
	gcc ${CFLAGS} -I include/ -I include/libft/include/ -Imlx -c $< -o $@

${NAME}:	${OBJ} ${HEADER}
			gcc ${CFLAGS} -I include/ -I include/libft/include/ -Linclude/libft/ -lft -Linclude/mlx -lmlx -framework OpenGL -framework AppKit ${ARCHIVES} ${OBJ} -o ${NAME}

clean:
			${RM} ${OBJ}
			make clean --no-print-directory -C include/libft
			make clean --no-print-directory -C include/mlx

fclean:		clean
			${RM} ${NAME}
			make fclean --no-print-directory -C include/libft

re:			fclean all

test: re
			./so_long map.ber

.PHONY:		all clean fclean re test