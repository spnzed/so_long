/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:45:28 by aaronespino       #+#    #+#             */
/*   Updated: 2023/05/03 17:02:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber_walls(t_sizes *sizes)
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
			if (sizes->map[0][y] != '1'
			|| sizes->map[countst(sizes->map) - 1][y] != '1'
			|| sizes->map[x][0] != '1'
			|| sizes->map[x][ft_strlen(sizes->map[x]) - 1] != '1')
			{
				ft_putstr_fd("Error\nInvalid map\n", 2);
				exit (0);
			}
			y++;
		}
		x++;
	}
}

void	check_ber_rect(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		if (ft_strlen(sizes->map[x]) != ft_strlen(sizes->map[0]))
		{
			printf("Error\nMap isn´t rectangular\n");
			exit (0);
		}
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			y++;
		}
		x++;
	}
}

void	check_ber_chars(t_sizes *sizes)
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
			if (sizes->map[x][y] != '1' && sizes->map[x][y] != '0' &&
			sizes->map[x][y] != 'E' && sizes->map[x][y] != 'P' &&
			sizes->map[x][y] != 'C' && sizes->map[x][y] != '\n')
			{
				ft_putstr_fd("Error\nMap contains wrong characters\n", 2);
				exit (0);
			}
			y++;
		}
		x++;
	}
}

void	check_ber_elem(t_sizes *sizes)
{
	int	x;
	int	y;

	sizes->exit = 0;
	sizes->position = 0;
	sizes->coins = 0;
	x = -1;
	while (sizes->map[++x] != 0)
	{
		y = -1;
		while (sizes->map[x][++y] != '\0')
		{
			if (sizes->map[x][y] == 'E')
				sizes->exit++;
			else if (sizes->map[x][y] == 'P')
				sizes->position++;
			else if (sizes->map[x][y] == 'C')
				sizes->coins++;
		}
	}
	if (sizes->exit != 1 || sizes->position != 1 || sizes->coins < 1)
	{
		ft_putstr_fd("Error\nInvalid elements\n", 2);
		exit (0);
	}
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
