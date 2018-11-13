/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:43:35 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/08 16:43:37 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
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
		ft_putchar_fd('\n', fd);
	}
}
