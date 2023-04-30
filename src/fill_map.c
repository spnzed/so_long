/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:49:04 by aaronespino       #+#    #+#             */
/*   Updated: 2023/04/30 19:50:15 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_sizes *s)
{
	t_index	i;
	int		num;

	num = 0;
	i.x = 0;
	i.h = 0;
	while (s->map[i.x])
	{
		i.y = 0;
		i.w = 0;
		while (s->map[i.x][i.y] != '\n' && s->map[i.x][i.y])
		{
			s->spr[num] = put_sprite(s, i.x, i.y);
			if (s->spr[num] == NULL)
				exit(0);
			mlx_put_image_to_window(s->mlx_ptr, s->win,
				s->spr[num++], i.w, i.h);
			i.w += IMG_SIZE;
			i.y++;
		}
		i.h += IMG_SIZE;
		i.x++;
	}
}

void	*put_sprite(t_sizes *s, int x, int y)
{
	if (s->map[x][y] == '1')
		return (showing(s, "textures/wall.xpm"));
	else if (s->map[x][y] == '0')
		return (showing(s, "textures/floor.xpm"));
	else if (s->map[x][y] == 'C')
		return (showing(s, "textures/collectable.xpm"));
	else if (s->map[x][y] == 'E')
		return (showing(s, "textures/exit.xpm"));
	else if (s->map[x][y] == 'P')
		return (showing(s, "textures/hero.xpm"));
	else
		return (0);
}

void	*showing(t_sizes *s, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(s->mlx_ptr, image, &img_size, &img_size);
	return (img);
}

void	comprove_ber2(t_sizes *sizes)
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
			if (sizes->map[x][y] != '1' || sizes->map[x][y] != '0' || sizes->map[x][y] != 'E' || 
			sizes->map[x][y] != 'P' || sizes->map[x][y] != 'C' || sizes->map[x][y] != '\n')
			{
				printf("Map contains wrong characters\n");
				exit (0);
			}
			y++;
		}
		x++;
	}
}