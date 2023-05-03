/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:37:54 by aaespino          #+#    #+#             */
/*   Updated: 2022/04/07 17:38:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_hex(unsigned long p)
{
	int	ret;

	ret = 0;
	if (p >= 16)
	{
		ret += ft_printf_hex(p / 16);
		ret += ft_printf_hex(p % 16);
	}
	else
	{
		if (p <= 9)
		{
			p = p + '0';
			write (1, &p, 1);
			ret++;
		}
		else
		{
			p = p - 10 + 'a';
			write (1, &p, 1);
			ret++;
		}
	}
	return (ret);
}

void	ft_printf_hex2(unsigned long p)
{
	int	ret;

	ret = 0;
	if (p >= 16)
	{
		ft_printf_hex2(p / 16);
		ft_printf_hex2(p % 16);
	}
	else
	{
		if (p <= 9)
		{
			p = p + '0';
			write (1, &p, 1);
		}
		else
		{
			p = p - 10 + 'A';
			write (1, &p, 1);
		}
	}
}

int	ft_x_x2_len(unsigned int p)
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

int	ft_printf_x(unsigned int num)
{
	int	ret;

	ret = ft_x_x2_len(num);
	if (num == 0)
	{
		write(1, "0", 1);
		ret++;
	}
	else
		ft_printf_hex(num);
	return (ret);
}

int	ft_printf_x2(unsigned int num)
{
	int	ret;

	ret = ft_x_x2_len(num);
	if (num == 0)
	{
		write(1, "0", 1);
		ret++;
	}
	else
		ft_printf_hex2(num);
	return (ret);
}
