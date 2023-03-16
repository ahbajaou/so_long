/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 03:13:24 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/02/11 22:04:13 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*ptr;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	while (i < len && s[i])
		i++;
	ptr = malloc ((i + 1));
	if (!ptr)
		return (NULL);
	while (j < i)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}
