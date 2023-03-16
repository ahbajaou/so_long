/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_leght.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:29:03 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/08 02:41:05 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_leght(t_maps *go, t_win *win)
{
	go->i = 0;
	while (go->i < win->height)
	{
		go->len = ft_strlen(go->map[go->i]);
		if (go->len != win->whidth)
			ft_error();
		go->i++;
	}
}
