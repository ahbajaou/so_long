/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:18:22 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/05 22:28:55 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_win *win)
{
	int	x;
	int	y;

	player_move(win);
	x = win->height * 50;
	y = win->whidth * 50;
	if (win->new_map[win->px + 1][win->py] == 'C')
	{
		win->new_map[win->px + 1][win->py] = '0';
		win->coin--;
	}
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./back.xpm", &y, &x);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, win->py * 50, win->px * 50);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
	win->px += 1;
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./mario2.xpm", &y, &x);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, win->py * 50, win->px * 50);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
}
