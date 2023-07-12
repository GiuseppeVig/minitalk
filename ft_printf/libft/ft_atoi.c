/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:04:16 by gvigilan          #+#    #+#             */
/*   Updated: 2023/03/29 14:50:48 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *nptr)
{
	int	n;
	int	neg;

	neg = 1;
	n = 0;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n += *nptr - 48;
		if (!ft_isdigit(*(nptr + 1)))
			break ;
		n *= 10;
		nptr ++;
	}
	return (n * neg);
}
