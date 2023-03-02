/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img_in_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:59:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 18:19:57 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_handler(int key,t_win *win)
{
    (void)win;

    printf("%d\n",key);
    return (0);
}
void set_img_in_win(t_maps *go)
{  

    t_win *win;

    win = malloc(sizeof(t_win));
	int x = go->height * 50;
	int  y = go->whidth * 50;

    win->mlx_ptr = mlx_init();
    win->mlx_win = mlx_new_window(win->mlx_ptr, y, x, "so_long");
    set_back_in_win(go,win);
    set_wall_in_win(go,win);
    set_collec_in_win(go,win);
    set_player_in_win(go,win);
    mlx_key_hook(win->mlx_win,key_handler,&win);
	mlx_loop(win->mlx_ptr);
}
