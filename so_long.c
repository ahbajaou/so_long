/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/02/14 17:40:53 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int ft_ber(char *a)
{
	int i = 0;
	int j = 0;
	char str[] = ".ber";
	while (a[i])
		i++;
	while (str[j])
		j++;
	i -= 1;
	j -= 1;
	while (j > 0)
	{
		if (str[j] == a[i])
		{
			i--;
			j--;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

void ft_error(void)
{
	printf("Error\n");
	exit(1);
}
void check_firstandlastline(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else
			ft_error();
	}
}
void	check_all_line(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (line[0] == '1' && line[21] == '1')
			i++;
		else
			ft_error();
	}
}
char  *ft_check_new_line(char *line)
{
	int i = 0;
	int len = ft_strlen((char *)line) - 1;
	while (line[i])
	{
		if (line[0] == '\n' || line[len] == '\n')
			{
				ft_error();
			}
			i++;
	}
	return (line);
}
void	check_char_in_map(char **line,int i)
{
	int len = ft_strlen((char *)line) - 1;
	while (i <= len)
	{
		int l = 0;
		while (line[i][l])
		{
			if (line[i][l] == '1' || line[i][l] == '0' || line[i][l] == 'E' || line[i][l] == 'C' || line[i][l] == 'P')
			{
				l++;
			}
			else
				ft_error();
		}
		i++;
	}
}
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd;
		char *tmp;
		char *new = NULL;
		char **map;

		if (!ft_ber(av[1]))
			return (0);
		fd = open("maps.ber", O_RDONLY);
		tmp = get_next_line(fd);
		while(tmp)
		{
			new = ft_strjoin(new,tmp);
			free(tmp);
			tmp = get_next_line(fd);
		}
		new = ft_check_new_line(new);
		map = ft_split(new, '\n');
		int len = ft_strlen((char *)map);
		int i = 0;
		while (i <= len)
		{
			int l = 0;
			if (i == 0 || i == (int)ft_strlen((char *)map[i]) - 1)
			{
				int j = 0;
				int k = 0;
				while (map[0][j])
				{
					check_firstandlastline(&map[0][j]);
					j++;
				}
				while (map[8][k])
				{
					check_firstandlastline(&map[8][k]);
					k++;
				}
				
			}
			else if (i == 1 || i == (int)ft_strlen((char *)map[i] - 1))
			{
				check_char_in_map(map,i);
			}
			check_all_line(&map[i][l]);
		
			// printf("here");
			i++;
		}
		return (0);
	// 	str = get_map(fd);
	// 	map = ft_split(str, '\n');
		// system("leaks so_long");
	}
	else
		printf("---Please enter 2 argument---");
}