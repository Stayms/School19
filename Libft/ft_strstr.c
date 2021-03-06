/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:40:28 by nbouchez          #+#    #+#             */
/*   Updated: 2018/08/16 15:40:30 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	char *to_find_tmp;
	char *str_tmp;

	while (*str != '\0')
	{
		str_tmp = (char*)str;
		to_find_tmp = (char*)to_find;
		while (*to_find_tmp == *str_tmp || *to_find_tmp == '\0')
		{
			if (*to_find_tmp == '\0')
			{
				return ((char*)str);
			}
			to_find_tmp++;
			str_tmp++;
		}
		str++;
	}
	if (*to_find == '\0')
		return ((char*)str);
	return ((char*)0);
}
