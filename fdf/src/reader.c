/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <nbouchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 08:01:43 by nbouchez          #+#    #+#             */
/*   Updated: 2019/03/14 13:05:32 by rpousseu         ###   ########.fr       */
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

	size = 0;
	fd = open(file, O_RDONLY);
	while ((status = read(fd, buff, 128)) > 0)
		size += status;
	close(fd);
	if (!(map = ft_strnew(size)) || status < 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	status = read(fd, map, size);
	return (ft_strsplit(map, '\n'));
}

char	check_map(char **map)
{
	int		i;
	int		j;
	int		cnt;
	int		tmp;

	i = -1;
	tmp = 0;
	while (map[++i])
	{
		cnt = 0;
		j = -1;
		while (map[i][++j])
			if (map[i][j] == ' ' && map[i][j + 1] != ' ')
				++cnt;
		if (cnt != tmp && tmp != 0)
			return (0);
		else
			tmp = cnt;
	}
	return (1);
}

int		get_map_size(char **map_split, int *x, int *y)
{
	int		i;
	int		check;
	int		tmp;

	tmp = 0;
	*y = -1;
	while (map_split[++(*y)])
	{
		check = 0;
		i = -1;
		*x = 0;
		while (map_split[*y][++i])
		{
			if (map_split[*y][i] != ' ' && map_split[*y][i] != '-'
					&& (map_split[*y][i] < '0' || map_split[*y][i] > '9'))
				return (-1);
			if (map_split[*y][i] == ' ' && map_split[*y][i - 1] != ' '
					&& map_split[*y][i + 1] != '\0')
				++(*x);
		}
	}
	return (++(*x) * *y);
}

int		add_to_int_array(char **line_split, int pos, int *array)
{
	int		i;

	i = -1;
	while (line_split[++i])
		array[pos++] = ft_atoi(line_split[i]);
	return (i);
}

int		*reader(char *file, int *x, int *y)
{
	char	**map_split;
	int		*array;
	int		pos;
	int		i;

	i = -1;
	pos = 0;
	if (!(map_split = get_map_split(file)))
		return (NULL);
	if (!check_map(map_split))
		return (NULL);
	if (!(array = (int*)malloc(get_map_size(map_split, x, y) * sizeof(int))))
		return (NULL);
	while (map_split[++i])
		pos += add_to_int_array(ft_strsplit(map_split[i], ' '), pos, array);
	return (array);
}
