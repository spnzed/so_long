/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:36:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/04/26 17:47:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void em(char **map)
{
	char	*aux;
	int		i;

	i = 0;
	aux = *map;
	while (aux[i])
	{
		free(&aux[i]);
		i++;
	}
	free(aux);
}

int	main2(t_sizes sizes)
{
	comprove_ber(&sizes);
	rect_map(&sizes);
	elem_map(&sizes);
	if (!comprove_way(&sizes))
	{
		printf("Error\nWay is invalid\n");
		em(sizes.map);
		return (0);
	}
	sizes.spr = calloc(sizeof(void *), (sizes.len));
	if (!sizes.spr)
		return (0);
	window(&sizes);
	mapping(&sizes);
	sizes.coins = count_coins(&sizes);
	mlx_hook(sizes.win, 2, 0, check_esc, &sizes);
	mlx_hook(sizes.win, 17, 0, close_it, &sizes);
	mlx_loop(sizes.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sizes	sizes;

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) != 0)
		return (0);
	sizes.moves = 0;
	sizes.len = read_len(argv[1]);
	if (argc != 2)
		return (0);
	sizes.map = read_map(argv[1]);
	sizes.map_aux = read_map(argv[1]);
	return (main2(sizes));
}
