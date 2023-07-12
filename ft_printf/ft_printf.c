/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:41:40 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/27 17:41:40 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handlevalue(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'x')
		return (ft_unsigned(va_arg(args, unsigned int), 16, ESA));
	if (c == 'X')
		return (ft_unsigned(va_arg(args, unsigned int), 16, UPPERESA));
	if (c == 'p')
		return (ft_print_memory(va_arg(args, unsigned long)));
	if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int), 10, "0123456789"));
	if (c == '%')
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				c;
	static int		temp;

	va_start(args, format);
	c = 0;
	temp = 0;
	while (format[c])
	{
		if (format[c] == '%')
		{
			c++;
			temp += handlevalue(format[c], args);
			c++;
			continue ;
		}
		else
			temp += ft_putchar(format[c]);
		c++;
	}
	va_end(args);
	return (temp);
}
