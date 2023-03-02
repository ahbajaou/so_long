/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:41:49 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:42:05 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_flood_fill(char **maps,int x,int y, t_maps *go)
{
	static int tmp_coins;
	if (x >= 8 || y >= 21 || maps[x][y] == '1' || maps[x][y] == '*')
		return 0;
	if (maps[x][y] == 'C')
		tmp_coins++;
	maps[x][y] = '*';
	ft_flood_fill(maps,x + 1, y, go);
	ft_flood_fill(maps,x, y + 1, go);
	ft_flood_fill(maps,x - 1, y, go);
	ft_flood_fill(maps,x, y - 1, go);
	return tmp_coins;
}