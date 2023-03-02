/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:27:57 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:28:20 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_char_in_map(char **line,int i)
{
	int len = ft_strlen((char *)line) - 1;
	while (i <= len)
	{
		int l = 0;
		while (line[i][l])
		{
			if (line[i][l] == '1' || line[i][l] == '0' || line[i][l] == 'E' || line[i][l] == 'C' || line[i][l] == 'P')
			{
				l++;
			}
			else
				ft_error();
		}
		i++;
	}
}