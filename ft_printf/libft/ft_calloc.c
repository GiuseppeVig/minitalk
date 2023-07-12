/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:06:37 by gvigilan          #+#    #+#             */
/*   Updated: 2023/03/31 22:39:11 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (0);
	ft_bzero(temp, (count * size));
	return (temp);
}
