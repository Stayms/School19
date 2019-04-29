# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 22:25:13 by nbouchez          #+#    #+#              #
#    Updated: 2018/11/20 22:25:14 by nbouchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDE = minilibx/mlx.h
SOURCE =
SOURCE_FILE = main.c scene_manager.c draw_line.c draw_iso.c draw_con.c reader.c ../libft/libft.a

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m Loading ...\033[0;37m"
	@cd ../libft && make re
	@clear
	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m Loading ...\033[0;37m"
	@cd ../minilibx_macos && make re
	@clear
	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36m$(NAME) --> Compilation --> \033[1;32m Loading ...\033[0;37m"
	@gcc -Wall -Wextra -Werror -o $(NAME) -I ../minilibx_macos -L ../minilibx_macos $(SOURCE_FILE) -framework OpenGL -framework OpenGL -framework AppKit -lmlx
	@clear
	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36m$(NAME) --> Compilation --> \033[1;32m OK\033[0;37m"

clean :
	@echo "\033[0;37m"
	@/bin/rm -f $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m$(NAME) --> Clean --> \033[1;32m OK\033[0;37m"
	@cd ../libft && make clean

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;36m$(NAME) --> Fclean --> \033[1;32m OK\033[0;37m"
	@cd ../libft && make fclean	

re : fclean all

.PHONY: $(NAME) all clean fclean re
