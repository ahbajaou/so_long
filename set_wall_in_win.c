/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_in_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:55:23 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 23:21:09 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_wall_in_win(t_win *win)
{
    int x = win->height * 50;
	int  y = win->whidth * 50;
    int i = 0;
    int j;
        win->i = 0;
        while (win->new_map[win->i])
		{
            win->j = 0;
            j = 0;
            while (win->new_map[win->i][win->j])
            {
                if (win->new_map[win->i][win->j] == '1')
                {
                     win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./hit.xpm", &y, &x);
		             mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->mlx_img, j, i);
		              mlx_destroy_image(win->mlx_ptr, win->mlx_img); 
                }
                j+=50;
                win->j++;
            }
            i+=50;
            win->i++;
		}
}