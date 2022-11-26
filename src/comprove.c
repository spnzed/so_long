/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:45:28 by aaronespino       #+#    #+#             */
/*   Updated: 2022/11/26 22:03:16 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void comprove_ber(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map [x][y] != '\0')
		{
			if (sizes->map[0][y] != '1'
			||	sizes->map[countst(sizes->map) - 1][y] != '1'
			||	sizes->map[x][0] != '1'
			||	sizes->map[x][ft_strlen(sizes->map[x]) - 1] != '1')
			{
				ft_printf("Error\ninvalid map\n");
				exit(0);
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
			ft_printf("Error\Map isn´t rectangular\n");
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
	if (sizes->exit < 1 || sizes->position < 1 || sizes->coins < 1)
	{
		ft_printf("Error\nMissing elements\n");
		exit (0);
	}
}