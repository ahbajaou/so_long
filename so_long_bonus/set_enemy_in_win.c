/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_in_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:22:06 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/17 11:06:54 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawin_enemy(t_win *win, int j, int i)
{
	int	x;
	int	y;

	x = win->height * 50;
	y = win->whidth * 50;
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, \
	"./enma.xpm", &y, &x);
	if (!win->mlx_img)
		ft_error();
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, j, i);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
}

void	set_enemy_in_win(t_win *win)
{
	int	j;
	int	i;

	i = 0;
	win->i = 0;
	while (win->new_map[win->i])
	{
		win->j = 0;
		j = 0;
		while (win->new_map[win->i][win->j])
		{
			if (win->new_map[win->i][win->j] == 'F')
			{
				drawin_enemy(win, j, i);
			}
			j += 50;
			win->j++;
		}
		i += 50;
		win->i++;
	}
}
