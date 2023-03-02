/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collec_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:08 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/02 17:43:30 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_collec_flood(char **maps,int x,int y, t_maps *go)
{
	int i = ft_flood_fill(maps,x,y, go);
	if (i == go->coin)
		return 1;
	ft_error();
	return 0;
}