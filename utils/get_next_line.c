/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:38:04 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/02/11 21:59:01 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_free_join(char *stati, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(stati, buf);
	return (tmp);
}

char	*ft_save_stati(char *stati)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = 0;
	if (!stati)
		return (NULL);
	if (!stati[0])
	{
		free(stati);
		return (NULL);
	}
	while (stati[i] && stati[i] != '\n')
		i++;
	str = ft_substr(stati, i + 1, (ft_strlen(stati) - i));
	free(stati);
	return (str);
}

char	*ft_find_ster(char *stati)
{
	int	i;

	i = 0;
	if (!stati[0])
		return (NULL);
	while (stati[i] && stati[i] != '\n')
		i++;
	return (ft_substr(stati, 0, i + 1));
}

char	*ft_read_stati(int fd, char *stati)
{
	int			nb;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nb = 1;
	while (!ft_strchr(stati) && nb != 0)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb == -1)
		{
			if (stati)
				free(stati);
			free(buf);
			return (NULL);
		}
		buf[nb] = '\0';
		stati = ft_free_join(stati, buf);
	}
	free(buf);
	return (stati);
}

char	*get_next_line(int fd)
{
	char			*ster;
	static char		*stati;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stati = ft_read_stati(fd, stati);
	if (!stati)
		return (NULL);
	ster = ft_find_ster(stati);
	stati = ft_save_stati(stati);
	return (ster);
}


