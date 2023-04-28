/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:44:10 by aaronespino       #+#    #+#             */
/*   Updated: 2023/04/28 17:22:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc)
{
	if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
		exit(0);
	}
	if (argc < 2)
	{
		printf("Error\nThe Map file is missing\n");
		exit(0);
	}
}

void	check_extension(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i > 2 && map[i - 4] == '.' && map[i - 3] == 'b'
		&& map[i - 2] == 'e' && map[i - 1] == 'r')
		;
	else
	{
		printf("Error\n The file does not have the correct extension\n");
		exit (0);
	}
}

int	read_len(char *map)
{
	int		fd;
	char	*buff;
	int		len;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	len = read(fd, buff, BUFFER_SIZE);
	free(buff);
	close(fd);
	return (len);
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
	free(buff);
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
		return ;
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
	check_path(sizes, x, y - 1);
}
