# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 21:09:39 by ahbajaou          #+#    #+#              #
#    Updated: 2023/02/22 16:45:22 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRC = utils/*.c
so_long = so_long.c $(SRC)
MLX = -lmlx -framework OpenGL -framework AppKit
all : so_long

so_long : $(so_long)
	cc $(CFLAGS) $(MLX) $(so_long) -o so_long
	
clean : 
	rm -f so_long

fclean : clean

re: fclean all