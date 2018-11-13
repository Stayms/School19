/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:54:50 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/09 13:54:51 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_char(char **ps)
{
	int		compteur;
	char	*pslocal;

	compteur = 0;
	while (**ps == ' ' || **ps == '\n' || **ps == '\t')
		*ps = *ps + 1;
	pslocal = *ps;
	if (**ps == '\0')
		return (0);
	while (*pslocal != '\0')
	{
		compteur++;
		pslocal++;
	}
	pslocal--;
	while (*pslocal == ' ' || *pslocal == '\n' || *pslocal == '\t')
	{
		compteur--;
		pslocal--;
	}
	return (compteur);
}

char			*ft_strtrim(char const *s)
{
	int		size;
	char	*ps;
	char	*psmalloc;

	psmalloc = ((char *)NULL);
	if (s)
	{
		ps = (char *)s;
		size = count_char(&ps);
		psmalloc = (char *)malloc(sizeof(char) * (size + 1));
		if (psmalloc == NULL)
			return ((char *)NULL);
		ft_strncpy(psmalloc, ps, size);
		psmalloc[size] = '\0';
	}
	return (psmalloc);
}
