/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:36:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/06 19:24:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_sizes(t_sizes *aux)
{
	t_sizes	sizes;

	sizes = *aux;
	sizes.mlx_ptr = 0;
	sizes.win = 0;
	sizes.spr = 0;
	sizes.map = 0;
	sizes.map_aux = 0;
	sizes.hx = 0;
	sizes.hy = 0;
	sizes.moves = 0;
	sizes.len = 0;
	sizes.coins = 0;
	sizes.exit = 0;
	sizes.position = 0;
}

int	main(int argc, char **argv)
{
	t_sizes	sizes;

	init_sizes(&sizes);
	check_arg(argc, argv);
	prepare_sizes(&sizes, argv);
	check_ber(sizes);
	prepare_2_print(&sizes);
	mlx_hook(sizes.win, 2, 0, check_esc, &sizes);
	mlx_hook(sizes.win, 17, 0, close_it, &sizes);
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
