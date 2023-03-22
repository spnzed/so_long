/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:47:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/03/22 17:16:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countst(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
		i++;
	return (i);
}

void	window(t_sizes *sizes)
{
	int	ancho;
	int	alto;

	ancho = ft_strlen(sizes->map[0]) * IMG_SIZE;
	alto = countst(sizes->map) * IMG_SIZE;
	sizes->mlx_ptr = mlx_init();
	sizes->win = mlx_new_window(sizes->mlx_ptr, (ancho), (alto), "so_long");
}

int	comprove_way(t_sizes *sizes)
{
	int		is_possible;
	int		aux_coins;
	int		x;
	int		y;

	aux_coins = sizes->coins;
	found_hero(sizes);
	x = sizes->hx;
	y = sizes->hy;
	check_path(sizes, x, y);
	is_possible = 1;
	if (sizes->coins != 0 || sizes->exit != 0 || sizes->position != 0)
		is_possible = 0;
	sizes->coins = aux_coins;
	sizes->exit = 1;
	sizes->position = 1;
	return (is_possible);
}
