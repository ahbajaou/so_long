# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 21:09:39 by ahbajaou          #+#    #+#              #
#    Updated: 2023/02/11 21:59:48 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRC = utils/*.c
so_long = so_long.c $(SRC) 
all : so_long

so_long : $(so_long)
	cc $(CFLAGS) $(so_long) -o so_long
	
clean : 
	rm -f so_long

fclean : clean

re: fclean all