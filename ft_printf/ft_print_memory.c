/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:21:19 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/11 21:21:19 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_pt(unsigned long nb, unsigned int bs, char *base)
{
	int	len;

	len = 0;
	if (nb >= bs)
		len += ft_unsigned_pt(nb / bs, bs, base);
	len += write(1, &base[nb % bs], 1);
	return (len);
}

int	ft_print_memory(unsigned long nb)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	len += ft_unsigned_pt(nb, 16, "0123456789abcdef");
	return (len);
}
