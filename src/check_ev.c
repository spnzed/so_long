/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:35:58 by aaespino          #+#    #+#             */
/*   Updated: 2023/05/04 16:28:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/ft_printf.h"

void	check_ev_arg(int argc, char **argv)
{
	if (argc != 2)
		exit (0);
	check_arguments(argc);
	check_extension(argv[1]);
}

void	check_ev_ber(t_sizes sizes)
{
	check_ber_walls(&sizes);
	check_ber_chars(&sizes);
	check_ber_rect(&sizes);
	check_ber_elem(&sizes);
	if (!check_way(&sizes))
	{
		ft_printf("Error\nWay is invalid\n");
		while (*sizes.map)
		{
			free(*sizes.map);
			sizes.map++;
		}
		exit (0);
	}
}

void	prepare_sizes(t_sizes *sizes, char **argv)
{
	sizes->moves = 0;
	sizes->len = read_len(argv[1]);
	sizes->map = read_map(argv[1]);
	sizes->map_aux = read_map(argv[1]);
}

void	prepare_2_print(t_sizes *sizes)
{
	sizes->spr = calloc(sizeof(void *), (sizes->len));
	if (!sizes->spr)
		exit (0);
	window(sizes);
	mapping(sizes);
	sizes->coins = count_coins(sizes);
}
