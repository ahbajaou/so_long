/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:00 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/08 02:37:44 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_all_line(t_maps *go, t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (go->map[i])
	{
		j = 0;
		while (go->map[i][j])
		{
			if (go->map[i][0] != '1' || go->map[i][win->whidth - 1] != '1')
				ft_error();
			j++;
		}
		i++;
	}
}
