NAME		=	so_long

CFLAGS		=	-Wall -Werror -Wextra -MMD

SRC 		=	srcs/comprove_ber/check_ber.c \
				srcs/comprove_ber/check_map.c \
				srcs/comprove_ber/check_way.c \
				srcs/comprove_ber/coins_exits.c \
				srcs/game_engine/checkprepare.c \
				srcs/game_engine/move_hero.c \
				srcs/graphics_module/map_to_screen.c \
				srcs/graphics_module/put_sprite.c \
				srcs/graphics_module/refresh_sprite.c \
				srcs/so_long.c \


OBJ			=	${SRC:.c=.o}
DEPS		=	${SRC:.c=.d}

ARCHIVES	=	include/libft/libft.a include/mlx/libmlx.a

DO			=	Makefile

RM 			=	rm -f

HEADER		=	include/so_long.h

INCLUDE		=	-I include/ -I include/mlx/ -I include/libft/include/

all:
	@make --no-print-directory -C include/libft
	@make --no-print-directory -C include/mlx
	@make --no-print-directory ${NAME}

%.o: %.c	${ARCHIVES} ${DO}
			gcc ${CFLAGS} ${INCLUDE} -c $< -o $@

${NAME}:	${OBJ}
			gcc ${CFLAGS} ${INCLUDE} -Linclude/libft/ -lft -Linclude/mlx -lmlx -framework OpenGL -framework AppKit ${OBJ} -o ${NAME}

clean:
			${RM} ${OBJ} ${DEPS}
			make clean --no-print-directory -C include/libft
			make clean --no-print-directory -C include/mlx

fclean:		clean
			${RM} ${NAME}
			make fclean --no-print-directory -C include/libft

re:			fclean all

test: re
			./so_long map.ber

-include $(DEPS)

.PHONY:		all clean fclean re test make
