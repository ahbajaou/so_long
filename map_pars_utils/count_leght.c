/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_leght.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:29:03 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 16:53:02 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_leght(char *line, int len)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i == len)
	{
		i = len;
	}
	else
		ft_error();
}
