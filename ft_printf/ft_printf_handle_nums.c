/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_nums.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:38:00 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/09 19:38:00 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	handleneg(int val, int base)
{
	if (val == -2147483648)
	{
		if (base == 2)
		{
			write(1, "-10000000000000000000000000000000", 33);
			return (32);
		}
		if (base == 8)
		{
			write(1, "-20000000000", 12);
			return (12);
		}
		if (base == 10)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		if (base == 16)
		{
			write(1, "-80000000", 9);
			return (9);
		}
	}
	return (0);
}

int	ft_putnbr_base(int n, int b)
{
	int			c;
	char		temp;

	c = 0;
	if (n == -2147483648)
		return (handleneg(n, b));
	if (n < 0)
	{
		c += ft_putchar('-');
		n *= -1;
	}
	if (n >= b)
		c += ft_putnbr_base(n / b, b);
	if ((n % b) < 10)
	{
		temp = (n % b) + 48;
		c += ft_putchar(temp);
	}
	else
	{
		temp = (n % b) + 87;
		c += ft_putchar(temp);
	}
	return (c);
}

int	ft_unsigned(unsigned int nb, unsigned int bs, char *base)
{
	int	len;

	len = 0;
	if (nb >= bs)
		len += ft_unsigned(nb / bs, bs, base);
	len += write(1, &base[nb % bs], 1);
	return (len);
}
