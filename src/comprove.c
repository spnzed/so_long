/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:45:28 by aaronespino       #+#    #+#             */
/*   Updated: 2023/01/25 15:40:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	comprove_ber(t_sizes *sizes)
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
				printf("Error\ninvalid map\n");
				exit (0);
			}
			y++;
		}
		x++;
	}
}

void rect_map(t_sizes *sizes)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		if(ft_strlen(sizes->map[x]) != ft_strlen(sizes->map[0]))
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

void elem_map(t_sizes *sizes)
{
	int x;
	int y;

	sizes->exit = 0;
	sizes->position = 0;
	sizes->coins = 0;
	x = -1;
	while (sizes->map[++x] != 0)
	{
		y = -1;
		while (sizes->map[x][++y] != '\0')
		if (sizes->map[x][y] == 'E')
			sizes->exit++;
		else if (sizes->map[x][y] == 'P')
			sizes->position++;
		else if (sizes->map[x][y] == 'C')
			sizes->coins++;
	}
	if (sizes->exit != 1 || sizes->position != 1 || sizes->coins < 1)
	{
		printf("Error\nInvalid elements\n");
		exit (0);
	}
}

int count_coins(t_sizes *sizes)
{
	unsigned int x;
	unsigned int y;
	unsigned int counter;

	x = 0;
	y = 0;
	counter = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			if (sizes->map[x][y] == 'C')
				counter++;
			y++;
		}
		x++;
	}
	
	return (counter);
}

int count_exits(t_sizes *sizes)
{
	unsigned int x;
	unsigned int y;
	unsigned int counter;

	x = 0;
	y = 0;
	counter = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			if (sizes->map[x][y] == 'E')
				counter++;
			y++;
		}
		x++;
	}
	
	return (counter);
}
