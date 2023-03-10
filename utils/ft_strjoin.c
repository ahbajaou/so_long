/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:12:35 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/09 22:46:39 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	new = malloc ((ft_strlen(s2) + ft_strlen(s1)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i < j)
	{
		new[i] = s1[i];
		i++;
	}
	j = ft_strlen(s2);
	k = 0;
	while (k < j)
		new[i++] = s2[k++];
	new[i] = 0;
	free (s1);
	return (new);
}
