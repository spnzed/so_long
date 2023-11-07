/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:44:10 by aaronespino       #+#    #+#             */
/*   Updated: 2023/11/07 15:44:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	check_arguments(int argc)
{
	if (argc > 2)
	{
		ft_printf("Error\nToo many arguments\n");
		exit(0);
	}
	if (argc < 2)
	{
		ft_printf("Error\nThe Map file is missing\n");
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
		ft_printf("Error\nThe file does not have the correct extension\n");
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
