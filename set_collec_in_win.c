/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_in_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:48:51 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 16:52:03 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    set_collec_in_win(t_maps *go,t_win *win)
{
    int x = go->height * 50;
	int  y = go->whidth * 50;
    int i = 0;
    int j;
        win->i = 0;
        while (go->new_map[win->i])
		{
            win->j = 0;
            j = 0;
            while (go->new_map[win->i][win->j])
            {
                if (go->new_map[win->i][win->j] == 'C')
                {
                     win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./collec2.xpm", &y, &x);
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