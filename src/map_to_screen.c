/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:47:55 by aaronespino       #+#    #+#             */
/*   Updated: 2022/11/26 20:56:34 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int countst(char **res)
{
	int i;

	i = 0;
	while (res[i] != 0)
		i++;
	return(i);
}

void window(t_sizes *sizes)
{
	int ancho;
	int alto;

	ancho = ft_strlen(sizes->map[0]) * IMG_SIZE;
	alto = countst(sizes->map) * IMG_SIZE;
	sizes->mlx_ptr = mlx_init();
	sizes->win = mlx_new_window(sizes->mlx_ptr, (ancho), (alto), "so_long");
}