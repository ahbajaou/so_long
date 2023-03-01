/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:10:04 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/02/25 23:33:14 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG
# define SO_LONG

# include <stdarg.h>
# include <signal.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

typedef struct s_win{
    int cnt;
    int in;
    int i;
    int j;
    void	*mlx;

} t_win;

typedef struct s_maps{
    int px;
    int py;
    int len;
    int index;
    int x;
    int whidth;
    int height;
    int coin;
    char **map;
    char **new_map;
} t_maps;


void put_back(t_maps *go);
void put_wall(t_maps *go);
char	*get_next_line(int fd);
char	**ft_split(char *s, char c);
int		ft_strchr(char *str);
char *ft_strcpy(char *dst,char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long int nb);
void	ft_hexad(unsigned long int nb, char *h, int *np);

#endif