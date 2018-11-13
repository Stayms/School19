/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 02:38:53 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/18 02:38:55 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *dest_tmp;

	dest_tmp = dest;
	while (*src != '\0')
	{
		*dest_tmp = *src;
		dest_tmp++;
		src++;
	}
	*dest_tmp = *src;
	return (dest);
}
