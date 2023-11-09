/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:07:29 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/07 15:45:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

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
				ft_printf("Error\nInvalid map\n");
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
			ft_printf("Error\nMap isn´t rectangular\n");
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
				ft_printf("Error\nMap contains wrong characters\n");
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
		ft_printf("Error\nInvalid elements\n");
		exit (0);
	}
}
