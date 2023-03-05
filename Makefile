# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 21:09:39 by ahbajaou          #+#    #+#              #
#    Updated: 2023/03/05 23:03:07 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRC = utils/*.c  map_pars_utils/*.c set_img_in_win.c set_back_in_win.c set_collec_in_win.c set_wall_in_win.c set_player_in_win.c set_door_in_win.c move_up.c move_right.c move_left.c move_down.c eat_coin_exit.c player_move.c ft_printf.c 
so_long = so_long.c $(SRC)
MLX = -lmlx -framework OpenGL -framework AppKit 
all : so_long

so_long : $(so_long)
	cc $(CFLAGS) $(MLX) $(so_long) -o so_long
	
clean : 
	rm -f so_long

fclean : clean

re: fclean all