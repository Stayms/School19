/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 02:07:14 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/19 02:07:15 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*output;

	if ((output = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	output->next = ((t_list*)NULL);
	if (content == NULL)
	{
		output->content = NULL;
		output->content_size = 0;
	}
	else
	{
		output->content = malloc(content_size);
		if (output->content == NULL)
		{
			free(output);
			return (NULL);
		}
		ft_memcpy(output->content, content, content_size);
		output->content_size = content_size;
	}
	return (output);
}
