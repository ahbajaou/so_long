/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:22:58 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/02/11 22:01:20 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_c(const char *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		count++;
		i++;
	}
	return (count);
}

int	count_word(const char *str, char c)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i] != c && str[i + 1] == '\0'))
			wd++;
		i++;
	}
	return (wd);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		sp;
	int		xc;
	char	**spl;
	int		x;

	sp = 0;
	i = 0;
	xc = count_word(s, c);
	spl = malloc(sizeof(char *) * (xc + 1));
	if (!spl)
		return (NULL);
	while (i < xc)
	{
		while (s[sp] && s[sp] == c)
			sp++;
		x = count_c(s, c, sp);
		spl[i] = ft_substr(s, sp, x);
		sp += x + 1;
		i++;
	}
	spl[i] = NULL;
	return (spl);
}
