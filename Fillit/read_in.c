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

t_piece read_in(const char *file_name)
{
	int fd;
	char *line
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
	    free(line);
	    line = NULL;
	}
}
