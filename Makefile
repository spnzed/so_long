NAME 	= so_long

CFLAGS = -Wall -Werror -Wextra

SRC = 	src/comprove.c \
		src/fill_map.c \
		src/map_to_screen.c \
		src/move.c \
		src/read.c \
		src/sprite_reaction.c \
		src/so_long.c \
		src/check_ev.c \
		src/count.c \


OBJ 	= ${SRC:.c=.o}

ARCHIVES	= libft/libft.a mlx/libmlx.a

RM 		= rm -f

HEADER	= src/so_long.h

all:
	@make --no-print-directory -C libft
	@make --no-print-directory -C mlx libmlx.a
	@make --no-print-directory ${NAME}

%.o: %.c	${HEADER} ${ARCHIVES}
	gcc ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJ} ${HEADER}
			gcc ${CFLAGS} -Llibft/ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit ${ARCHIVES} ${OBJ} -o ${NAME} -I include/ -I libft/include/

clean:
			${RM} ${OBJ}
			make clean --no-print-directory -C libft
			make clean --no-print-directory -C mlx

fclean:		clean
			${RM} ${NAME}
			make fclean --no-print-directory -C libft

re:			fclean all

test: re
			./so_long map.ber

.PHONY:		all clean fclean re test