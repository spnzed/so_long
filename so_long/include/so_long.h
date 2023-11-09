/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:46:24 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 19:33:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../include/mlx/mlx.h"
# include "../include/libft/include/libft.h"
# define BUFFER_SIZE 4096
# define IMG_SIZE 32

typedef struct s_sizes
{
	void	*mlx_ptr;
	void	*win;
	void	**spr;
	char	**map;
	char	**map_aux;
	int		hx;
	int		hy;
	int		moves;
	int		len;
	int		coins;
	int		exit;
	int		position;
}	t_sizes;

typedef struct s_index
{
	int		x;
	int		y;
	int		h;
	int		w;
}	t_index;

typedef struct s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}	t_coord;

//	comprove_ber
//check_ber.c
void	check_arguments(int argc);
void	check_extension(char *map);
int		read_len(char *map);
char	**read_map(char *map);
//check_map.c
void	check_ber_walls(t_sizes *sizes);
void	check_ber_rect(t_sizes *sizes);
void	check_ber_chars(t_sizes *sizes);
void	check_ber_elem(t_sizes *sizes);
//check_way.c
void	check_path(t_sizes *sizes, int x, int y);
int		check_way(t_sizes *sizes);
//coins_exits.c
int		count_coins(t_sizes *sizes);
int		count_exits(t_sizes *sizes);
//	game_engine
//checkprepare.c
void	check_arg(int argc, char **argv);
void	prepare_sizes(t_sizes *sizes, char **argv);
void	check_ber(t_sizes sizes);
void	prepare_2_print(t_sizes *sizes);
//move_hero.c
void	*lets_swap(int x, int y, t_sizes *sizes);
void	found_hero(t_sizes *sizes);
int		lets_move(int keycap, t_sizes *sizes);
int		close_it(void);
int		check_esc(int keycap, t_sizes *sizes);
//	graphics_module
//map_to_screen.c
int		countst(char **res);
void	window(t_sizes *sizes);
//put_sprite.c
void	*showing(t_sizes *s, char *image);
void	*put_sprite(t_sizes *s, int x, int y);
void	mapping(t_sizes *s);
//refresh_sprite.c
void	remove_spr(t_sizes *sizes);
void	**save_spr(t_sizes *sizes);

#endif
