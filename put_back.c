/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:59:36 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/01 17:41:21 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    key_handler(int key,t_maps *go)
{
    (void)go;
    printf("-----%d\n",key);
    return (0);
}
void put_back(t_maps *go)
{  
    void	*mlx_img;
    void    *mlx_ptr;
    void    *mlx_win;
    t_win win;

	int x = go->height * 50;
	int  y = go->whidth * 50;
    int i = 0;
    int j;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, y, x, "so_long");
	while (i < go->height * 50)
		{

            j = 0;
            while (j < go->whidth * 50)
            {
		        mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./wall2d2.xpm", &y, &x);
		        mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, j, i);
		        mlx_destroy_image(mlx_ptr, mlx_img); 
                j+=50;
            }
            i+=50;
		}
        i = 0;
        win.i = 0;
        while (go->new_map[win.i])
		{
            win.j = 0;
            j = 0;
            while (go->new_map[win.i][win.j])
            {
                if (go->new_map[win.i][win.j] == '1')
                {
                     mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./wall2.xpm", &y, &x);
		             mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, j, i);
		              mlx_destroy_image(mlx_ptr, mlx_img); 
                }
                j+=50;
                win.j++;
            }
            i+=50;
            win.i++;
		}
        i = 0;
        win.i = 0;
        while (go->new_map[win.i])
		{
            win.j = 0;
            j = 0;
            while (go->new_map[win.i][win.j])
            {
                if (go->new_map[win.i][win.j] == 'C')
                {
                     mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./collec2.xpm", &y, &x);
		             mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, j, i);
		              mlx_destroy_image(mlx_ptr, mlx_img); 
                }
                j+=50;
                win.j++;
            }
            i+=50;
            win.i++;
		}
        i = 0;
        win.i = 0;
        while (go->new_map[win.i])
		{
            win.j = 0;
            j = 0;
            while (go->new_map[win.i][win.j])
            {
                if (go->new_map[win.i][win.j] == 'P')
                {
                     mlx_img = mlx_xpm_file_to_image(mlx_ptr, "./player.xpm", &y, &x);
		             mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, j, i);
		              mlx_destroy_image(mlx_ptr, mlx_img); 
                }
                j+=50;
                win.j++;
            }
            i+=50;
            win.i++;
		}
        mlx_key_hook(mlx_win,key_handler,&go);
		mlx_loop(mlx_ptr);
}
