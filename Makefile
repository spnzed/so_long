NAME 	= so_long

CFLAGS = -Wall -Werror -Wextra

SRC = 	src/comprove.c \
		src/fill_map.c \
		src/map_to_screen.c \
		src/move.c \
		src/read.c \
		src/sprite_reaction.c \
		src/so_long.c \


OBJ 	= ${SRC:.c=.o}

RM 		= rm -f

HEADER	= src/so_long.h

.c.o:	
	make -C libft
	make -C mlx
	gcc -c ${CFLAGS} -Imlx $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rc ${NAME} ${OBJ}
			gcc ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a ${NAME} -o so_long

clean:
			${RM} ${OBJ}
			make clean -C libft
			make clean -C mlx

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft

re:			fclean all

test: re
			./so_long map.ber

.PHONY:		all clean fclean re