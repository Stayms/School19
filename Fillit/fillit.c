/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:07:20 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/13 22:07:22 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage()
{
	write(1,"usage: ./fillit source_file\n",28);
}

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		usage();
		return (0);
	}
	read_in(argv[1]);

	return (0);
}
