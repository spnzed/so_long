/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns_per.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:39:17 by aaespino          #+#    #+#             */
/*   Updated: 2022/04/07 17:39:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_printf_unsigned_char(unsigned int num)
{
	int		len;
	char	*str;

	len = ft_printf_unsigned_len(num);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_printf_unsigned_len(unsigned int num)
{
	int	ret;

	ret = 0;
	while (num != 0)
	{
		num = num / 10;
		ret++;
	}
	return (ret);
}

int	ft_printf_unsigned(unsigned int num)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (!num)
	{
		write (1, "0", 1);
		len++;
	}
	else
	{
		str = ft_printf_unsigned_char(num);
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			i++;
			len = i;
		}
		free(str);
	}
	return (len);
}

int	ft_printf_percent(void)
{
	write(1, "%", 1);
	return (1);
}
