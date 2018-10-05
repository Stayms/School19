/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:32:28 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/18 03:32:29 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 < *s2)
		{
			return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
		}
		if (*s2 < *s1)
		{
			return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
