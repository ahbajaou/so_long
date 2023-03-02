/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    check_player_exit_collec.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:34:48 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:35:20 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_player_exit_collec(char **line,t_maps *go)
{
	int len = 0;
	int j = 0;
	int i = 0;
	int p = 0;
	int e = 0;
	go->coin = 0;
	while (line[len])
		len++;
	while (i < len)
	{
		while (line[i][j])
		{
			if (line[i][j] == 'C')
			{
				go->coin++;
			}
			if (line[i][j] == 'P')
			{
				p++;
			}
			if (line[i][j] == 'E')
			{
				e++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (go->coin < 1 || e != 1 || p != 1)
	{
		ft_error();
	}

}