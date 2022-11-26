/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:51:21 by aaronespino       #+#    #+#             */
/*   Updated: 2022/11/26 21:00:18 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_it(void)
{
	exit(0);
}

void *lets_swap(int x, int y, t_sizes *sizes)
{
	remove_spr(sizes);
	mlx_clear_window(sizes->mlx_ptr, sizes->win);
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'C')
		sizes->coins--;
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E' && sizes->coins == 0)
		mlx_destroy_window(sizes->mlx, sizes->win);
		exit(0);
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E' && sizes->coins > 0)
	{
		mapping(sizes);
		return (0);
	}
	sizes->map[sizes->hx + x][sizes->hy + y] = 'P';
	sizes->map[sizes->hx][sizes->hy] = '0';
	sizes->spr = save_spr(sizes);
	sizes->moves++;
	printf("Moves:%d\n", sizes->moves);
	mapping(sizes);
	return (0);
}

void found_hero(t_sizes *sizes)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			if (sizes->map[x][y] == 'P')
				break;
			y++;
		}
		if (sizes->map[x][y] == 'P')
			break;
		x++;
	}
	sizes->hx = x;
	sizes->hy = y;
}

int lets_move(int keycap, t_sizes *sizes)
{
		found_hero(sizes);
		if((keycap == 0 || keycap 123) && sizes->map[sizes->hx][sizes->hy - 1] != '1')
		lets_swap(0, -1, sizes);
		if((keycap == 13 || keycap 126) && sizes->map[sizes->hx - 1][sizes->hy] != '1')
		lets_swap(-1, 0, sizes);
		if((keycap == 2 || keycap 124) && sizes->map[sizes->hx][sizes->hy + 1] != '1')
		lets_swap(0, +1, sizes);
		if((keycap == 1 || keycap 125) && sizes->map[sizes->hx + 1][sizes->hy] != '1')
		lets_swap(+1, 0, sizes);
		else
			return (0);
}

int check_esc(int keycap, t_sizes *sizes)
{
	if (keycap == 53)
		close_it();
	else
		lets_move(keycap, sizes);
	return (0);
}