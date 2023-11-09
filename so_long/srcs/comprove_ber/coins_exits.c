/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_exits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:45:49 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 18:46:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	counter;

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

int	count_exits(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	counter;

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
