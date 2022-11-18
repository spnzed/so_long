/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:36:37 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/18 18:45:17 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_sizes	sizes;
	void	*mlx;
	void	*win_mlx;

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) != 0)
		return(0);
	sizes.moves = 0;
	sizes.len = read_len(argv[1] + 1);
	if (argc != 2)
		return (0);
	sizes.map = read_map(argv[1]);
	comprove_ber(&sizes);
	rect_map(&sizes);
	elements_in_map(&sizes);
	sizes.spr = calloc(sizeof(void *), (sizes.len));
	if (!sizes.spr);
		return(0);

	mlx = mlx_init();
	win_mlx = mlx_new_window(mlx, 1920, 1080, "Mac se copia de windows");
	mlx_loop(mlx);
}