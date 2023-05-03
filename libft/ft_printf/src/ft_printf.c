/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:16:02 by aaespino          #+#    #+#             */
/*   Updated: 2022/04/07 17:39:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arguments(const char *convert, va_list args, int i)
{
	int	ret;

	ret = 0;
	if (convert[i] == 'c')
		ret = ft_printf_char(va_arg(args, int));
	else if (convert[i] == 's')
		ret = ft_printf_string(va_arg(args, char *));
	else if (convert[i] == 'p')
		ret = ft_printf_pointer(va_arg(args, unsigned long));
	else if (convert[i] == 'd' || convert[i] == 'i')
		ret = ft_printf_integrer(va_arg(args, int));
	else if (convert[i] == 'u')
		ret = ft_printf_unsigned(va_arg(args, unsigned int));
	else if (convert[i] == 'x')
		ret = ft_printf_x(va_arg(args, unsigned int));
	else if (convert[i] == 'X')
		ret = ft_printf_x2(va_arg(args, unsigned int));
	else if (convert[i] == '%')
		ret = ft_printf_percent();
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			ret += ft_printf_arguments(input, args, i + 1);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			ret++;
		}
		i++;
	}
	va_end (args);
	return (ret);
}
