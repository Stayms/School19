/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:07:40 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/13 22:48:16 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

t_coord *read_in(const char *file_name)
{
	static t_coord tab[26][3];
	int fd;
	char *line;
	char tab_tmp[546 + 1];

	if((fd = open(file_name, O_RDONLY)) == 0)
		return ((t_coord*)NULL);
	if(read(fd, tab_tmp, BUFF_SIZE) > 545)
	    return ((t_coord*)NULL);
	else
	{
		printf("OK");
	}
	return (NULL);

}
