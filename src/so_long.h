/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:46:24 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/26 22:02:10 by aaronespino      ###   ########.fr       */
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


void comprove_ber(t_sizes *sizes);
void rect_map(t_sizes *sizes);
void elem_map(t_sizes *sizes);

void mapping(t_sizes *s);
void *put_sprite(t_sizes *s, int x, int y);
void *showing(t_sizes *s, char *image);

int countst(char **res);
void window(t_sizes *sizes);

int	close_it(void);
void *lets_swap(int x, int y, t_sizes *sizes);
void found_hero(t_sizes *sizes);
int lets_move(int keycap, t_sizes *sizes);
int check_esc(int keycap, t_sizes *sizes);

int	read_len(char *map);
char	**read_map(char *map);

void remove_spr(t_sizes *sizes);
void **save_spr(t_sizes *sizes);


#endif
