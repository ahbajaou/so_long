/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:14:13 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/10 03:00:04 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*part_itoa(int j, int i, long nb)
{
	char	*str;

	if (nb < 0)
		str = malloc(sizeof (char) * (i + 2));
	else
		str = malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (j > 0)
	{
		if (nb < 0)
		{
			str[0] = '-';
			i = 1;
			nb *= -1;
		}
		str[i] = ((nb / j) + 48);
		nb -= ((nb / j) * j);
		j /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		j;
	int		i;
	long	tmp;
	long	nb;

	i = 1;
	j = 1;
	nb = n;
	tmp = nb;
	if (tmp < 0)
		tmp *= -1;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		j *= 10;
		i++;
	}
	return (part_itoa(j, i, nb));
}
