/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:19 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/01 01:08:15 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(to_find))
		return ((char *)dest);
	if (!n)
		return (NULL);
	while (dest[i] && i < n)
	{
		j = 0;
		while (dest[i + j] == to_find[j] && (i + j) < n)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)(dest + i));
		}	
		i ++;
	}
	return (0);
}
