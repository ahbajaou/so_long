/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:22:55 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 23:23:33 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_win *win)
{
	int	x;
	int	y;

	x = win->height * 50;
	y = win->whidth * 50;
	if (win->new_map[win->px][win->py + 1] == 'C')
	{
		win->new_map[win->px][win->py + 1] = '0';
		win->coin--;
	}
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./back.xpm", &y, &x);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, win->py * 50, win->px * 50);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
	win->py += 1;
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./mario.xpm", &y, &x);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, win->py * 50, win->px * 50);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
}
