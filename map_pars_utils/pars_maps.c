/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:36:20 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/08 02:42:00 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pars_maps(t_maps *go, t_win *win)
{
	go->i = 0;
	while (go->map[win->height])
		win->height++;
	while (go->map[0][win->whidth])
		win->whidth++;
	count_leght(go, win);
	check_firstandlastline(go, win);
	check_all_line(go, win);
	check_player_exit_collec(go, win);
	check_char_in_map(go);
}
