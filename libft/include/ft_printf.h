/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:39:55 by marvin            #+#    #+#             */
/*   Updated: 2022/04/08 10:39:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *input, ...);
int			ft_printf_arguments(const char *convert, va_list args, int i);
int			ft_printf_char(int c);
int			ft_printf_string(char *str);
int			ft_printf_pointer(unsigned long p);
int			ft_printf_integrer(int num);
int			ft_printf_unsigned(unsigned int num);
char		*ft_printf_unsigned_char(unsigned int num);
int			ft_printf_unsigned_len(unsigned int num);
int			ft_printf_x(unsigned int num);
int			ft_printf_x2(unsigned int num);
int			ft_printf_hex(unsigned long p);
void		ft_printf_hex2(unsigned long p);
int			ft_x_x2_len(unsigned int p);
int			ft_printf_percent(void);

#endif