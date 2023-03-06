/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:14:17 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/06 22:25:48 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_ber(char *a)
{
	int		i;
	int		j;
	char	*str;

	str = ".ber";
	j = 0;
	i = 0;
	while (a[i])
		i++;
	while (str[j])
		j++;
	i -= 1;
	j -= 1;
	while (j >= 0 && str[j] == a[i])
	{
		i--;
		j--;
	}
	if (str[j + 1] != '.' || str[j + 1] != a[i + 1])
		ft_error();
}
