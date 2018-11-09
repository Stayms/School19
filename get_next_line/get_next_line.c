/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:39:20 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/27 19:39:21 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static	char	*join_res(char *s1, char *res, int *endofline)
{
	char		*result;
	size_t		res_size;

	result = ((char *)NULL);
	if (s1 && res)
	{
		result = ft_strnew(ft_strlen(s1) + ft_strlen(res));
		if (result == NULL)
			return (NULL);
		ft_strcpy(result, s1);
		if (ft_strchr(res, '\n') != NULL)
		{
			*endofline = 1;
			res_size = ft_strchr(res, '\n') - res;
		}
		else
		{
			res_size = ft_strlen(res);
		}
		ft_strncat(result, res, res_size);
		ft_memcpy(res, res + res_size + 1, BUFF_SIZE - res_size);
	}
	free(s1);
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	char		*ptab;
	int			read_value;
	static char	res[BUFF_SIZE + 1];
	int			endofline;

	endofline = 0;
	if (fd == -1 || line == NULL || (ptab = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if (ft_strlen(res) != 0 && (ptab = join_res(ptab, res, &endofline)))
		if (ft_strlen(res) != 0 && endofline == 1 && (*line = ptab))
			return (1);
	while (endofline == 0 && (read_value = read(fd, res, BUFF_SIZE)) > 0)
	{
		res[read_value] = '\0';
		ptab = join_res(ptab, res, &endofline);
	}
	if (read_value == -1)
		return (-1);
	if (ft_strlen(res) == 0 && read_value == 0 &&
		ft_strlen(ptab) == 0 && endofline == 0)
		return (0);
	*line = ptab;
	return (1);
}

int main()
{
	int i, fd;
	char *line;

    system("mkdir -p sandbox");
	system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 100000000 * 3/4)) 2> /dev/null");
	fd = open("sandbox/large_file.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
	    //write(1, line, strlen(line));
	    //write(1, "\n", 1);
	    free(line);
	    line = NULL;
	}
	return 0;
}