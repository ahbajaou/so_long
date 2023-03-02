/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:20:00 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:20:20 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_all_line(char *line)
{
	int i = 0;
	int len = ft_strlen((char *)line) - 1;
	while (line[i])
	{
		if (line[0] == '1' && line[len] == '1')
			i++;
		else
			ft_error();
	}
}