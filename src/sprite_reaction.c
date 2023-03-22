/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_reaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:55:11 by aaronespino       #+#    #+#             */
/*   Updated: 2023/03/22 16:15:46 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_spr(t_sizes *sizes)
{
	int	i;

	i = 0;
	while (sizes->spr[i])
	{
		mlx_destroy_image(sizes->mlx_ptr, sizes->spr[i]);
		i++;
	}
}

void	**save_spr(t_sizes *sizes)
{
	sizes->spr = calloc(sizeof(void *), (sizes->len));
	if (!sizes->spr)
		return (0);
	return (sizes->spr);
}
