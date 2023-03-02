/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collec_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:08 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 22:59:31 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_collec_flood(char **maps,int x,int y, t_maps *go ,t_win *win)
{
	int i = ft_flood_fill(maps,x,y,win);
	if (i == go->coin)
		return 1;
	ft_error();
	return 0;
}