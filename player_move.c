/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:20:16 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/14 03:45:36 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_win *win, int j, int i)
{
	int	x;
	int	y;

	x = win->height * 50;
	y = win->whidth * 50;
	win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, \
	"./hit.xpm", &y, &x);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, \
	win->mlx_img, j, i);
	mlx_destroy_image(win->mlx_ptr, win->mlx_img);
}

void	set_wall_move(t_win *win)
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
			if (win->new_map[win->i][win->j] == '1')
			{
				drawin_wall(win, 0, 0);
			}
			j += 50;
			win->j++;
		}
		i += 50;
		win->i++;
	}
}

void	player_move(t_win *win)
{
	set_wall_move(win);
	win->player++;
	win->moves = ft_itoa(win->player);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 0, 0, 0xFFFFFF, win->moves);
	ft_printf("--Move : %d\n", win->player);
	free(win->moves);
}
