/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/05 20:57:14 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_next_map(t_maps *go)
{
	go->tmp = get_next_line(go->fd);
	while (go->tmp)
	{
		go->new = ft_strjoin(go->new, go->tmp);
		free(go->tmp);
		go->tmp = get_next_line(go->fd);
	}
}

int	main(int ac, char **av)
{
	t_maps	*go;
	t_win	*win;

	win = malloc(sizeof(t_win));
	go = malloc(sizeof(t_maps));
	if (ac == 2)
	{
		ft_ber(av[1]);
		go->fd = open(av[1], O_RDONLY);
		if (go->fd < 0)
			return (0);
		get_next_map(go);
		go->new = ft_check_new_line(go->new);
		go->map = ft_split(go->new, '\n');
		win->new_map = ft_split(go->new, '\n');
		pars_maps(go->map, go, win);
		player_position(go->map, win);
		check_collec_flood(win->px, win->py, go, win);
		set_img_in_win(win);
	}
	else
		write(1, "---Please enter 2 argument---\n", 31);
}
