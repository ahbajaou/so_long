/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    check_player_exit_collec.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:34:48 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 20:48:42 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_player_exit_collec(char **line, t_maps *go, t_win *win)
{
	go->j = 0;
	go->i = 0;
	go->p = 0;
	go->e = 0;
	go->coin = 0;
	while (go->i < win->height)
	{
		while (line[go->i][go->j])
		{
			if (line[go->i][go->j] == 'C')
				go->coin++;
			if (line[go->i][go->j] == 'P')
				go->p++;
			if (line[go->i][go->j] == 'E')
				go->e++;
			go->j++;
		}
		go->i++;
		go->j = 0;
	}
	if (go->coin < 1 || go->e != 1 || go->p != 1)
	{
		ft_error();
	}
	win->coin = go->coin;
}
