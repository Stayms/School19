/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:54:32 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/23 09:54:32 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	int fd;
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
