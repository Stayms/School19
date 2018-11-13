# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 20:25:44 by nbouchez          #+#    #+#              #
#    Updated: 2018/10/03 20:25:45 by nbouchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = 
SOURCE = 
SOURCE_FILE =	ft_atoi ft_strcmp ft_strdup ft_strncat ft_strncpy ft_strcat \
				ft_strcpy ft_strlen ft_strncmp ft_strstr ft_memset ft_bzero ft_memccpy \
				ft_memmove ft_isalpha ft_isdigit ft_memcpy ft_strchr ft_strrchr ft_isalnum \
				ft_isascii ft_isprint ft_tolower ft_toupper ft_strnstr ft_memalloc ft_memdel \
				ft_strnew ft_strdel ft_strclr ft_strequ ft_strnequ ft_memchr ft_memcmp ft_striter \
				ft_striteri ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd \
				ft_putendl_fd ft_putnbr_fd ft_itoa ft_strsub ft_strjoin ft_strtrim ft_strmap ft_strmapi \
				ft_strlcat ft_strsplit ft_free_my_2dtab ft_lstnew ft_lstadd ft_lstdelone ft_lstdel \
				ft_lstiter ft_lstmap

all: $(NAME)

$(NAME): $(addsuffix .c, $(addprefix $(SOURCE),$(SOURCE_FILE)))
	@gcc -Werror -Wextra -Wall -c $(addsuffix .c, $(addprefix $(SOURCE),$(SOURCE_FILE)))
	@ar -rcs $(NAME) $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m $(NAME) --> Compilation --> \033[1;32m OK\033[0;37m"

clean :
	@echo "\033[0;37m"
	@/bin/rm -f $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m $(NAME) --> Clean --> \033[1;32m OK\033[0;37m"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;36m $(NAME) --> Fclean --> \033[1;32m OK\033[0;37m"

re : fclean all