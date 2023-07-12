/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:25:30 by gvigilan          #+#    #+#             */
/*   Updated: 2023/03/28 12:07:31 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sp1;
	unsigned char	*sp2;

	sp1 = (unsigned char *) s1;
	sp2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*(sp1 + i) != *(sp2 + i))
			return (*(sp1 + i) - *(sp2 + i));
		i ++;
	}
	return (0);
}
