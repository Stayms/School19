/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:48:23 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/13 22:48:24 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef	struct		s_piece
{
	t_coord			origin;
	t_coord			coord[4];
}					t_piece;

t_piece read_in(const char *file_name);

#endif
