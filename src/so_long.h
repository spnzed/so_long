/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:46:24 by aaespino          #+#    #+#             */
/*   Updated: 2023/04/26 16:50:21 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
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

void	comprove_ber(t_sizes *sizes);
void	rect_map(t_sizes *sizes);
void	elem_map(t_sizes *sizes);
int		count_coins(t_sizes *sizes);

void	mapping(t_sizes *s);
void	*put_sprite(t_sizes *s, int x, int y);
void	*showing(t_sizes *s, char *image);

int		countst(char **res);
void	window(t_sizes *sizes);
int		comprove_way(t_sizes *sizes);
void	put_error(char *str);

int		close_it(void);
void	*lets_swap(int x, int y, t_sizes *sizes);
void	found_hero(t_sizes *sizes);
int		lets_move(int keycap, t_sizes *sizes);
int		check_esc(int keycap, t_sizes *sizes);

int		read_len(char *map);
char	**read_map(char *map);
void	check_path(t_sizes *sizes, int x, int y);

void	remove_spr(t_sizes *sizes);
void	**save_spr(t_sizes *sizes);

#endif
