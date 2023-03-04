/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:04 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/04 23:45:28 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

typedef struct s_win{
	int		cnt;
	int		in;
	int		i;
	int		j;
	int		px;
	int		py;
	int		coin;
	int		whidth;
	int		height;
	char	**new_map;
	void	*mlx_img;
	void	*mlx_ptr;
	void	*mlx_win;
}	t_win;

typedef struct s_maps{
	int		len;
	int		index;
	int		x;
	int		coin;
	int		fd;
	int		p;
	int		e;
	int		i;
	int		j;
	int		l;
	char	*tmp;
	char	*new;
	char	**map;
}	t_maps;

void	set_img_in_win(t_win *win);
void	set_back_in_win(t_win *win);
void	set_wall_in_win(t_win *win);
void	set_collec_in_win(t_win *win);
void	set_player_in_win(t_win *win);
void	set_door_in_win(t_win *win);
void	eat_coin_exit(t_win *win, int key);
void	move_right(t_win *win);
void	move_left(t_win *win);
void	move_up(t_win *win);
void	move_down(t_win *win);
void	ft_ber(char *a);
void	ft_error(void);
void	count_leght(char *line, int len);
void	check_player_exit_collec(char **line, t_maps *go, t_win *win);
void	pars_maps(char **map, t_maps *go, t_win *win);
void	player_position(char **maps, t_win *win);
int		check_collec_flood(int x, int y, t_maps *go, t_win *win);
int		ft_flood_fill(char **maps, int x, int y, t_win *win);
void	check_char_in_map(char **line, int i);
char	*ft_check_new_line(char *line);
void	check_all_line(char *line);
void	check_firstandlastline(char *line);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
int		ft_strchr(char *str);
char	*ft_strcpy(char *dst, char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif