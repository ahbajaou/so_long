# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 21:09:39 by ahbajaou          #+#    #+#              #
#    Updated: 2023/03/16 21:34:45 by ahbajaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRC = utils/*.c  map_pars_utils/*.c set_img_in_win.c set_back_in_win.c set_collec_in_win.c set_wall_in_win.c \
	set_player_in_win.c set_door_in_win.c move_up.c move_right.c move_left.c move_down.c eat_coin_exit.c \
	player_move.c ft_printf.c  so_long.c

SRC_BONUS = utils/*.c so_long_bonus/map_pars_utils/*.c so_long_bonus/set_img_in_win.c \
so_long_bonus/set_back_in_win.c so_long_bonus/set_collec_in_win.c so_long_bonus/set_wall_in_win.c \
	so_long_bonus/set_player_in_win.c so_long_bonus/set_door_in_win.c so_long_bonus/move_up.c \
	so_long_bonus/move_right.c so_long_bonus/move_left.c so_long_bonus/move_down.c so_long_bonus/eat_coin_exit.c \
	so_long_bonus/player_move.c so_long_bonus/ft_printf.c so_long_bonus/set_enemy_in_win.c so_long_bonus/so_long.c
	
MLX = -lmlx -framework OpenGL -framework AppKit

all : so_long
so_long_bonus : bonus
so_long : $(SRC)
	cc $(FLAGS) $(SRC) $(MLX) -o so_long

bonus : $(SRC_BONUS)
	cc $(FLAGS) $(SRC_BONUS) $(MLX) -o bonus

clean:
	rm -f *.o
fclean: clean
	rm -rf so_long bonus
re: fclean all



