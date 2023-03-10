/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:27:57 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/08 03:17:42 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_char_in_map(t_maps *go)
{
	int	i;
	int	j;

	i = 0;
	while (go->map[i])
	{
		j = 0;
		while (go->map[i][j])
		{
			if (!(go->map[i][j] == '1' || go->map[i][j] == '0'
				|| go->map[i][j] == 'P' || go->map[i][j] == 'E'
					|| go->map[i][j] == 'C' || go->map[i][j] == 'F'))
				ft_error();
			j++;
		}
		i++;
	}
}
