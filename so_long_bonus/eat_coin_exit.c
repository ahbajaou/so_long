/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_coin_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:33:48 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/09 23:05:12 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eat_coin_exit(t_win *win, int key)
{
	if ((key == 124 || key == 2) && win->new_map[win->px][win->py + 1] == 'E')
	{
		player_move(win);
		exit(0);
	}
	if ((key == 123 || key == 0) && win->new_map[win->px][win->py - 1] == 'E')
	{
		player_move(win);
		exit(0);
	}
	if ((key == 125 || key == 1) && win->new_map[win->px + 1][win->py] == 'E')
	{
		player_move(win);
		exit (0);
	}
	if ((key == 126 || key == 13) && win->new_map[win->px - 1][win->py] == 'E')
	{
		player_move(win);
		exit (0);
	}
}
