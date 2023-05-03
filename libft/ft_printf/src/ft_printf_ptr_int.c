/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:37:09 by aaespino          #+#    #+#             */
/*   Updated: 2022/04/07 17:37:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptr_len(unsigned int p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

int	ft_printf_pointer(unsigned long p)
{
	unsigned int	ret;

	write(1, "0x", 2);
	ret = 2;
	if (p == 0)
	{
		write (1, "0", 1);
		ret++;
	}
	else
		ret += ft_printf_hex(p);
	return (ret);
}

int	ft_printf_integrer(int num)
{
	char	*str;
	int		ret;

	str = ft_itoa (num);
	ret = ft_strlen(str);
	ft_putstr_fd (str, 1);
	free (str);
	return (ret);
}
