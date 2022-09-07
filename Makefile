# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 16:40:05 by vinograd          #+#    #+#              #
#    Updated: 2022/05/18 16:46:59 by ekantane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall
NAME = fdf
SRC = src/color.c src/deal_key.c src/error.c src/flat.c src/ft_wordcount.c src/isometric.c src/main.c
INCLUDES = libft/libft.a

.PHONY: all clean fclean re

all:
	@make -C libft/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) -L /usr/local/lib -lmlx -I /usr/local/include $(FRAMEWORKS)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
