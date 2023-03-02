/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 23:21:52 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_maps	*go;
	t_win *win;

    win = malloc(sizeof(t_win));
	go = malloc(sizeof(t_maps));

	if (ac == 2)
	{
		int fd;
		char *tmp;
		char *new = NULL;
		char **map;

		ft_ber(av[1]);
		fd = open(av[1], O_RDONLY);
		tmp = get_next_line(fd);
		while(tmp)
		{
			new = ft_strjoin(new,tmp);
			free(tmp);
			tmp = get_next_line(fd);
		}
		new = ft_check_new_line(new);
		map = ft_split(new, '\n');
		win->new_map = ft_split(new,'\n');

		pars_maps(map,go,win);
		player_position(map, win);
		check_collec_flood(map ,win->px,win->py,go,win);
		set_img_in_win(win);
	}
	else
		printf("---Please enter 2 argument---");
}