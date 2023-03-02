/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:39:05 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:39:28 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_position(char **maps,t_maps *go)
{
	int i = 0;
	int j;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'P')
			{
				go->px = i;
				go->py = j;
				break;
			}
			j++;
		}
		i++;
	}
}