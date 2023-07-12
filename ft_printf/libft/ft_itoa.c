/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:53:29 by gvigilan          #+#    #+#             */
/*   Updated: 2023/03/29 18:27:53 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	get_size(int value)
{
	int	num_of_chars;

	num_of_chars = 0;
	while (value > 0)
	{
		num_of_chars ++;
		value /= 10;
	}
	return (num_of_chars);
}

static char	*max_neg(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	ft_strlcpy(str, "-2147483648", 13);
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*number;

	size = 0;
	if (n == -2147483648)
		return (max_neg());
	size = get_size(ft_abs(n));
	if (n <= 0)
		size ++;
	number = (char *)malloc(size + 1);
	if (!number)
		return (0);
	if (n == 0)
		number[0] = '0';
	number[size--] = '\0';
	if (n < 0)
		number[0] = '-';
	n = ft_abs(n);
	while (n > 0)
	{
		number[size--] = ((n % 10) + 48);
		n /= 10;
	}
	return (number);
}
