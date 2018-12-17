/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 08:01:43 by nbouchez          #+#    #+#             */
/*   Updated: 2018/12/13 08:01:44 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

char	**get_map_split(char *file)
{
	char	buff[128];
	char	*map;
	int		fd;
	int		status;
	int		size;

	fd = open(file, O_RDONLY);
	while ((status = read(fd, buff, 128)) > 0)
		size += status;
	close(fd);
	if (!(map = ft_strnew(size)))
		return (NULL);
	fd = open(file, O_RDONLY);
	status = read(fd, map, size);
	return(ft_strsplit(map, '\n'));
}

int		get_map_size(char **map_split, int *x, int *y)
{
	int		i;

	*y = -1;
	while (map_split[++(*y)])
	{
		i = -1;
		*x = 0;
		while(map_split[*y][++i])
		{
			if (map_split[*y][i] == ' ' && map_split[*y][i - 1] != ' '
			&& map_split[*y][i + 1] != '\0')
				++(*x);
		}
	}
	return (++(*x) * *y);
}

int		add_to_int_array(char **line_split, int pos, int *final_array)
{
	int		i;

	i = -1;
	while(line_split[++i])
		final_array[pos++] = ft_atoi(line_split[i]);
	return (i);
}

int		*reader(char *file, int *x, int *y)
{
	char	**map_split;
	int		*final_array;
	int		pos;
	int		i;

	i = -1;
	pos = 0;
	if (!(map_split = get_map_split(file)))
		return (NULL);
	if (!(final_array = (int*)malloc(get_map_size(map_split, x, y) * sizeof(int))))
		return (NULL);
	while (map_split[++i])
		pos += add_to_int_array(ft_strsplit(map_split[i], ' '), pos, final_array);
	return (final_array);
}
