/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:36:20 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:36:47 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pars_maps(char **map,t_maps *go)
{
		while (map[go->height])
			go->height++;
		int i = 0;
		while (i < go->height)
		{
			int l = 0;
			int j = 0;
			while (map[0][go->whidth])
				go->whidth++;
			count_leght(&map[i][l],go->whidth);
			l = 0;
			if (i == 0 || i == go->height - 1)
			{
				j = 0;
				while (map[0][j])
				{
					check_firstandlastline(&map[0][j]);
					j++;
				}
				j = 0;
				while (map[go->height - 1][j])
				{
					check_firstandlastline(&map[go->height - 1][j]);
					j++;
				}
				
			}
			else if (i >= 1 && i <= go->height - 1)
			{
				check_char_in_map(map,i);
			}
			check_all_line(&map[i][l]);
			check_player_exit_collec(map, go);
			i++;
		}
}