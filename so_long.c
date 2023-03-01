/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:40:09 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/01 18:22:46 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

void ft_error(void)
{
	printf("Error\n");
	exit(1);
}

void  ft_ber(char *a)
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
			ft_error();
		}
	}
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
	int len = ft_strlen((char *)line) - 1;
	while (line[i])
	{
		if (line[0] == '1' && line[len] == '1')
			i++;
		else
			ft_error();
	}
}
char  *ft_check_new_line(char *line)
{
	int index = 0;
	int len = ft_strlen((char *)line);
	while (line[index])
	{
		if (line[index] == '\n' && line[index + 1] == '1' && line[index - 1] == '\n')
			{
				ft_error();
			}
		if (line[0] == '\n' || line[len - 1] == '\n')
			{
				ft_error();
			}
			index++;
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
void	count_leght(char *line,int len)
{
	int i = 0;
	while (line[i])
		i++;
	if (i == len)
	{

	}
	else
		ft_error();
}
void	check_player_exit_collec(char **line,t_maps *go)
{
	int len = 0;
	int j = 0;
	int i = 0;
	int p = 0;
	int e = 0;
	go->coin = 0;
	while (line[len])
		len++;
	while (i < len)
	{
		while (line[i][j])
		{
			if (line[i][j] == 'C')
			{
				go->coin++;
			}
			if (line[i][j] == 'P')
			{
				p++;
			}
			if (line[i][j] == 'E')
			{
				e++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (go->coin < 1 || e != 1 || p != 1)
	{
		ft_error();
	}

}
void	pars_maps(char **map,t_maps *go)
{
		while (map[go->height])
			go->height++;
		int i = 0;
		while (i < go->height)
		{
			int l = 0;
			int j = 0;
			while (map[0][go->whidth])
				go->whidth++;
			count_leght(&map[i][l],go->whidth);
			l = 0;
			if (i == 0 || i == go->height - 1)
			{
				j = 0;
				while (map[0][j])
				{
					check_firstandlastline(&map[0][j]);
					j++;
				}
				j = 0;
				while (map[go->height - 1][j])
				{
					check_firstandlastline(&map[go->height - 1][j]);
					j++;
				}
				
			}
			else if (i >= 1 && i <= go->height - 1)
			{
				check_char_in_map(map,i);
			}
			check_all_line(&map[i][l]);
			check_player_exit_collec(map, go);
			i++;
		}
}
void	ft_position(char **maps,t_maps *go)
{
	int i = 0;
	int j;
	while (maps[i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'P')
			{
				go->px = i;
				go->py = j;
				break;
			}
			j++;
		}
		i++;
	}
}

int	ft_flood_fill(char **maps,int x,int y, t_maps *go)
{
	static int tmp_coins;
	if (x >= 8 || y >= 21 || maps[x][y] == '1' || maps[x][y] == '*')
		return 0;
	if (maps[x][y] == 'C')
		tmp_coins++;
	maps[x][y] = '*';
	ft_flood_fill(maps,x + 1, y, go);
	ft_flood_fill(maps,x, y + 1, go);
	ft_flood_fill(maps,x - 1, y, go);
	ft_flood_fill(maps,x, y - 1, go);
	return tmp_coins;
}

int check_C(char **maps,int x,int y, t_maps *go)
{
	int i = ft_flood_fill(maps,x,y, go);
	if (i == go->coin)
		return 1;
	ft_error();
	return 0;
}




int main(int ac, char **av)
{
	t_maps	*go;
		
	go = malloc(sizeof(t_maps));

	if (ac == 2)
	{
		int fd;
		char *tmp;
		char *new = NULL;
		char **map;

		ft_ber(av[1]);
		fd = open(av[1], O_RDONLY);
		tmp = get_next_line(fd);
		while(tmp)
		{
			new = ft_strjoin(new,tmp);
			free(tmp);
			tmp = get_next_line(fd);
		}
		new = ft_check_new_line(new);
		map = ft_split(new, '\n');
		go->new_map = ft_split(new,'\n');

		pars_maps(map,go);
		ft_position(map, go);
		check_C(map ,go->px,go->py, go);
		put_back(go);
		put_wall(go);
	}
	else
		printf("---Please enter 2 argument---");
}