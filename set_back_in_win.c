/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_back_in_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:37:19 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 22:51:50 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_back_in_win(t_win *win)
{
    int x = win->height * 50;
	int  y = win->whidth * 50;
    int i = 0;
    int j;
    	while (i < win->height * 50)
		{

            j = 0;
            while (j < win->whidth * 50)
            {
		        win->mlx_img = mlx_xpm_file_to_image(win->mlx_ptr, "./back.xpm", &y, &x);
		        mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->mlx_img, j, i);
		        mlx_destroy_image(win->mlx_ptr, win->mlx_img); 
                j+=50;
            }
            i+=50;
		}
}