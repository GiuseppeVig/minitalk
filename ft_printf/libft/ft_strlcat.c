/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:03:50 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/01 00:48:29 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int		length;
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen(src));
	length = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && j + i < dstsize - 1)
	{
		dst[i + j] = src[j];
		j ++;
	}
	if (i < dstsize || !dstsize)
		dst[i + j] = '\0';
	else
		return (ft_strlen(src) + dstsize);
	return (length);
}
