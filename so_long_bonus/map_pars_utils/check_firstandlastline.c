/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_firstandlastline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:18:44 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/08 02:40:38 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_firstandlastline(t_maps *go, t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (go->map[i])
	{
		j = 0;
		while (go->map[i][j])
		{
			if (go->map[0][j] != '1')
				ft_error();
			if (i + 1 == win->height)
			{
				if (go->map[i][j] != '1')
					ft_error();
			}
			j++;
		}
		i++;
	}
}
