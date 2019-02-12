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

NAME = fractol
INCLUDE = minilibx/mlx.h
SOURCE = 
SOURCE_FILE = main.c scene_manager.c draw_point.c zoom.c maps/mandelbrot.c ../libft/libft.a ../get_next_line/get_next_line.c

all: $(NAME)

$(NAME):
	@clear
#	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m Loading ...\033[0;37m"
#	@cd ../libft && make re
#	@clear
#	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
#	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m Loading ...\033[0;37m"
#	@cd ../minilibx_macos && make re
#	@clear
#	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
#	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m OK\033[0;37m"
#	@echo "\033[1;36m$(NAME) --> Compilation --> \033[1;32m Loading ...\033[0;37m"
	@gcc -o $(NAME) -I ../minilibx_macos -L ../minilibx_macos $(SOURCE_FILE) -framework OpenGL -framework OpenGL -framework AppKit -lmlx
#	@clear
	@echo "\033[1;36mLibft --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36mLibx --> Compilation --> \033[1;32m OK\033[0;37m"
	@echo "\033[1;36m$(NAME) --> Compilation --> \033[1;32m OK\033[0;37m"

clean :
	@echo "\033[0;37m"
	@/bin/rm -f $(addsuffix .o, $(SOURCE_FILE))
	@echo "\033[1;36m$(NAME) --> Clean --> \033[1;32m OK\033[0;37m"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;36m$(NAME) --> Fclean --> \033[1;32m OK\033[0;37m"

re : fclean all