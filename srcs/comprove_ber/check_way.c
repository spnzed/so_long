/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:13:43 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 19:51:58 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../include/libft/include/ft_printf.h"

void	check_path(t_sizes *sizes, int x, int y)
{
	if (sizes->map_aux[x][y] == 'C')
		sizes->coins--;
	if (sizes->map_aux[x][y] == 'P')
		sizes->position--;
	if (sizes->map_aux[x][y] == 'E')
	{
		sizes->exit--;
		sizes->map_aux[x][y] = '1';
		return ;
	}
	if (sizes->map_aux[x][y] != '1')
	{
		sizes->map_aux[x][y] = '1';
	}
	else
		return ;
	check_path(sizes, x + 1, y);
	check_path(sizes, x, y + 1);
	check_path(sizes, x - 1, y);
	check_path(sizes, x, y - 1);
}

int	check_way(t_sizes *sizes)
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
