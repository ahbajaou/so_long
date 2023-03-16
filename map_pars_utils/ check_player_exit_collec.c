/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    check_player_exit_collec.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:34:48 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/16 11:34:34 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_player_exit_collec(t_maps *go, t_win *win)
{
	go->i = 0;
	go->p = 0;
	go->e = 0;
	go->f = 0;
	go->coin = 0;
	while (go->map[go->i])
	{
			go->j = 0;
		while (go->map[go->i][go->j])
		{
			if (go->map[go->i][go->j] == 'C')
				go->coin++;
			if (go->map[go->i][go->j] == 'P')
				go->p++;
			if (go->map[go->i][go->j] == 'E')
				go->e++;
			go->j++;
		}
		go->i++;
	}
	if (go->coin < 1 || go->e != 1 || go->p != 1)
		ft_error();
	win->coin = go->coin;
}
