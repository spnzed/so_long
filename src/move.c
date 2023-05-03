/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:51:21 by aaronespino       #+#    #+#             */
/*   Updated: 2023/05/03 19:19:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/ft_printf.h"

int	close_it(void)
{
	exit (0);
}

void	*lets_swap(int x, int y, t_sizes *sizes)
{
	void	**aux;

	remove_spr(sizes);
	mlx_clear_window(sizes->mlx_ptr, sizes->win);
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'C')
		sizes->coins--;
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E' && sizes->coins == 0)
		close_it();
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E' && sizes->coins > 0)
	{
		mapping(sizes);
		return (0);
	}
	sizes->map[sizes->hx + x][sizes->hy + y] = 'P';
	sizes->map[sizes->hx][sizes->hy] = '0';
	aux = sizes->spr;
	sizes->spr = save_spr(sizes);
	free(aux);
	sizes->moves++;
	ft_printf("Moves:%d\n", sizes->moves);
	mapping(sizes);
	return (0);
}

void	found_hero(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			if (sizes->map[x][y] == 'P')
				break ;
			y++;
		}
		if (sizes->map[x][y] == 'P')
			break ;
		x++;
	}
	sizes->hx = x;
	sizes->hy = y;
}

int	lets_move(int keycap, t_sizes *sizes)
{
	found_hero(sizes);
	if ((keycap == 0) && sizes->map[sizes->hx][sizes->hy - 1] != '1')
		lets_swap(0, -1, sizes);
	if ((keycap == 13) && sizes->map[sizes->hx - 1][sizes->hy] != '1')
		lets_swap(-1, 0, sizes);
	if ((keycap == 2) && sizes->map[sizes->hx][sizes->hy + 1] != '1')
		lets_swap(0, +1, sizes);
	if ((keycap == 1) && sizes->map[sizes->hx + 1][sizes->hy] != '1')
		lets_swap(+1, 0, sizes);
	else
		return (0);
	return (0);
}

int	check_esc(int keycap, t_sizes *sizes)
{
	if (keycap == 53)
		close_it();
	else
		lets_move(keycap, sizes);
	return (0);
}
