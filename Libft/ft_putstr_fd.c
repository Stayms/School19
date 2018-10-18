/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:40:33 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 16:40:34 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned char *cs;

	if (s && fd)
	{
		cs = (unsigned char*)s;
		while (*cs != '\0')
		{
			ft_putchar_fd(*cs, fd);
			cs++;
		}
	}
}
