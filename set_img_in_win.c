/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_in_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:59:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/16 11:42:00 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	preskey_handler(int key, t_win *win)
{
	if ((key == 124 || key == 2) && (win->new_map[win->px][win->py + 1] != '1'\
	&& win->new_map[win->px][win->py + 1] != 'E'))
		move_right(win);
	else if ((key == 123 || key == 0) && (win->new_map[win->px][win->py - 1]
		!= '1' && win->new_map[win->px][win->py - 1] != 'E'))
		move_left(win);
	else if ((key == 125 || key == 1) && (win->new_map[win->px + 1][win->py]
		!= '1' && win->new_map[win->px + 1][win->py] != 'E'))
		move_up(win);
	else if ((key == 126 || key == 13) && (win->new_map[win->px - 1][win->py]
		!= '1' && win->new_map[win->px - 1][win->py] != 'E'))
		move_down(win);
	else if (win->coin == 0)
		eat_coin_exit(win, key);
	else if (key == 53)
	{
		ft_printf("<Exit Game>");
		exit (0);
	}
	return (0);
}

void	set_img_in_win(t_win *win)
{
	int	x;
	int	y;

	x = win->height * 50;
	y = win->whidth * 50;
	win->mlx_ptr = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_ptr, y, x, "so_long");
	set_back_in_win(win);
	set_wall_in_win(win);
	set_collec_in_win(win);
	set_door_in_win(win);
	set_player_in_win(win);
	mlx_hook(win->mlx_win, 2, 0L, preskey_handler, win);
	mlx_hook(win->mlx_win, 17, 0L, (void *)exit, win);
	mlx_loop(win->mlx_ptr);
}
