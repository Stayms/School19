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
SOURCE = srcs/
SOURCE_FILE =	ft_atoi ft_strcmp ft_strdup ft_strncat ft_strncpy ft_strcat \
				ft_strcpy ft_strlen ft_strncmp ft_strstr ft_memset ft_bzero ft_memccpy \
				ft_memmove ft_isalpha ft_isdigit

all: $(NAME)

$(NAME): $(addsuffix .c, $(addprefix $(SOURCE),$(SOURCE_FILE)))
	gcc -Werror -Wextra -Wall -c $(addsuffix .c, $(addprefix $(SOURCE),$(SOURCE_FILE)))
	ar -rcs $(NAME) $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m $(NAME) --> Compilation --> \033[1;32m OK\033[0;37m"

clean :
	@echo "\033[0;37m"
	/bin/rm -f $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m $(NAME) --> Clean --> \033[1;32m OK\033[0;37m"

fclean : clean
	/bin/rm -f $(NAME)
	@echo "\033[1;36m $(NAME) --> Fclean --> \033[1;32m OK\033[0;37m"

re : fclean all