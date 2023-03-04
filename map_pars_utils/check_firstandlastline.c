/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_firstandlastline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:18:44 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 16:54:13 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_firstandlastline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
		{
			i++;
		}
		else
			ft_error();
	}
}
