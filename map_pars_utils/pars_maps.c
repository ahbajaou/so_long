/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:36:20 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 16:45:05 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pars_maps_2(char **map, t_win *win)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		check_firstandlastline(&map[0][j]);
		j++;
	}
	j = 0;
	while (map[win->height - 1][j])
	{
		check_firstandlastline(&map[win->height - 1][j]);
		j++;
	}
}

void	pars_maps(char **map, t_maps *go, t_win *win)
{
	go->i = 0;
	while (map[win->height])
		win->height++;
	while (go->i < win->height)
	{
		go->l = 0;
		go->j = 0;
		while (map[0][win->whidth])
			win->whidth++;
		count_leght(&map[go->i][go->l], win->whidth);
		go->l = 0;
		if (go->i == 0 || go->i == win->height - 1)
		{
			pars_maps_2(map, win);
		}
		else if (go->i >= 1 && go->i <= win->height - 1)
		{
			check_char_in_map(map, go->i);
		}
		check_all_line(&map[go->i][go->l]);
		check_player_exit_collec(map, go, win);
		go->i++;
	}
}
