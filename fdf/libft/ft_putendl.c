/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:50:00 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 15:53:36 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	unsigned char *cs;

	if (s)
	{
		cs = (unsigned char*)s;
		while (*cs != '\0')
		{
			ft_putchar(*cs);
			cs++;
		}
		ft_putchar('\n');
	}
}
