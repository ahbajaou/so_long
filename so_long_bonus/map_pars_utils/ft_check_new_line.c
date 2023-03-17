/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:26 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/17 15:15:39 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_check_new_line(char *line)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen((char *)line);
	if (line[0] == '\n')
		ft_error();
	while (line[index])
	{
		if (line[index] == '\n' && line[index + 1] == '\n')
			ft_error();
		index++;
	}
	return (line);
}
