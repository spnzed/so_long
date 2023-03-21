/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:44:10 by aaronespino       #+#    #+#             */
/*   Updated: 2023/03/21 18:46:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_len(char *map)
{
	int     fd;
	char    *buff;
	int		len;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	len = read(fd, buff, BUFFER_SIZE);

	free(buff);
	close(fd);
	return(len);
}

char	**read_map(char *map)
{
	int		fd;
	char	*buff;
	char	**res;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	res = ft_split(buff, '\n');
	//comprobar elem_map if invalid elements, free buff
	return (res);
}

void	check_path(t_sizes *sizes, int x, int y)
{
	if (sizes->map_aux[y][x] == 'C')
		sizes->coins--;
	if (sizes->map_aux[y][x] == 'P')
		sizes->position--;
	if (sizes->map_aux[y][x] == 'E')
	{
		sizes->exit--;
		sizes->map_aux[y][x] = '1';
		return;
	}
	if (sizes->map_aux[y][x] != '1')
	{
		sizes->map_aux[y][x] = '1';
	}
	else
		return ;
	check_path(sizes, x + 1, y);
	check_path(sizes, x, y + 1);
	check_path(sizes, x - 1, y);
	check_path(sizes, x ,y - 1);
}
