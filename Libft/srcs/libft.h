/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:48:42 by nbouchez          #+#    #+#             */
/*   Updated: 2018/10/03 19:48:44 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strncat(char *dest, char *src, int nb);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcat(char *dest, char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

int		ft_isalpha(int c);
int		ft_isdigit(int c);

#endif
