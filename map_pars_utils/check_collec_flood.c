/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collec_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:08 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/16 11:32:47 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_collec_flood(int x, int y, t_maps *go, t_win *win)
{
	int	i;

	i = ft_flood_fill(go->map, x, y, win);
	if (i != go->coin)
		ft_error();
	if (win->exit != 1)
		ft_error();
}
