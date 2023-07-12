/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:51:45 by gvigilan          #+#    #+#             */
/*   Updated: 2023/04/03 15:07:50 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	numofwords(const char *str, char sep)
{
	int	numwords;
	int	i;

	numwords = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i ++;
		if (str[i] != '\0')
			numwords ++;
		while (str[i] != sep && str[i])
			i ++;
	}
	return (numwords);
}

static char	*ft_strndup(const char *to_copy, int i, int j)
{
	char	*copy;
	int		n;

	if (!to_copy)
		return (0);
	n = 0;
	copy = (char *)malloc(i - j + 1);
	while (j < i)
	{
		copy[n] = to_copy[j];
		j ++;
		n ++;
	}
	copy[n] = '\0';
	return (copy);
}

static char	**ft_resolve(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	words = (char **)malloc(sizeof(char *) * (numofwords(s, c) + 1));
	if (!words)
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i ++;
		if (i > j)
		{
			words[k] = ft_strndup(s, i, j);
			k++;
		}
	}
	words[k] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (0);
	words = ft_resolve(s, c);
	return (words);
}
