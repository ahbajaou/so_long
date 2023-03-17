/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_back_in_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:37:19 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/17 11:13:10 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawin_back(t_win *win, int j, int i)
{
	int	x;
	int	y;

	x = win->height * 50;
	y = win->whidth * 50;
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, \
	"./back.xpm", &y, &x);
	if (!win->mlx_img)
		ft_error();
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, j, i);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
}

void	set_back_in_win(t_win *win)
{
	int	j;
	int	i;

	i = 0;
	while (i < win->height * 50)
	{
		j = 0;
		while (j < win->whidth * 50)
		{
			drawin_back(win, j, i);
			j += 50;
		}
		i += 50;
	}
}
