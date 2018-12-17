/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:21:28 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/14 12:21:29 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*copy_word(char *src, char c)
{
	int		i;
	char	*output;

	i = 0;
	while (src[i] != c && src[i] != '\0')
		i++;
	if ((output = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static	int		count_words(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

extern	char	**ft_strsplit(char const *s, char c)
{
	char	**output;
	int		i;
	int		x;
	char	*s2;

	if (!(s2 = (char*)s))
		return (NULL);
	if (!(output = malloc(sizeof(char*) * count_words(s2, c))))
		return (NULL);
	x = 0;
	i = 0;
	while (s2[i])
		if (s2[i] != c)
		{
			if ((output[x++] = copy_word(s2 + i, c)) == NULL)
			{
				return ((char**)ft_free_my_2dtab(output, x - 1));
			}
			while (s2[i] != c && s2[i] != '\0')
				i++;
		}
		else
			i++;
	output[x] = 0;
	return (output);
}
