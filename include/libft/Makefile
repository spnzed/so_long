NAME = libft.a

SRC_LIBFT_DIR = src/
SRC_LIBFT = 	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memset.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
				ft_strlcat.c ft_bzero.c ft_strchr.c ft_strrchr.c ft_memcpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strrncmp.c

SRC_FTPRINTF_DIR = ft_printf/src/
SRC_FTPRINTF =	ft_printf.c ft_printf_ch_str.c ft_printf_ptr_int.c ft_printf_uns_per.c \
				ft_printf_x_X.c

OBJ_LIBFT_DIR = obj/
OBJ_LIBFT_FILES = $(SRC_LIBFT:%.c=%.o)
OBJ_LIBFT = $(addprefix $(OBJ_LIBFT_DIR), $(OBJ_LIBFT_FILES))
OBJ_FTPRINTF_DIR = ft_printf/obj/
OBJ_FTPRINTF_FILES = $(SRC_FTPRINTF:%.c=%.o)
OBJ_FTPRINTF = $(addprefix $(OBJ_FTPRINTF_DIR), $(OBJ_FTPRINTF_FILES))
OBJS = $(OBJ_LIBFT) $(OBJ_FTPRINTF)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJ_LIBFT_DIR) $(OBJ_FTPRINTF_DIR) $(OBJS)
	@ar rc $@ $(OBJS)

$(OBJ_LIBFT_DIR):
	@mkdir $@
$(OBJ_FTPRINTF_DIR):
	@mkdir $@

$(OBJ_LIBFT_DIR)%.o: $(SRC_LIBFT_DIR)%.c
	$(CC) $(CFLAGS) -I include/ -c $< -o $@

$(OBJ_FTPRINTF_DIR)%.o:	$(SRC_FTPRINTF_DIR)%.c
	$(CC) $(CFLAGS) -I include/ -c $< -o $@

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
