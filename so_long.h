/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:46:24 by aaespino          #+#    #+#             */
/*   Updated: 2022/11/18 18:46:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_sizes
{
	void	**spr;
	char	**map;
	int		moves;
	int		len;
}	t_sizes;

int		read_len(char *map)
char	**read_map(char *map)
void	comprove_ber(t_sizes *sizes)

#endif
