/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:42:59 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/18 18:46:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return(len);
}

char	**read_map(char *map)
{
	int		fd;
	char	*buff;
	int		res;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	res = ft_split(buff, '\n');
	return (res);
}

void	comprove_ber(t_sizes *sizes)
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
