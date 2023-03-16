/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbajaou <ahbajaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:50:47 by ahbajaou          #+#    #+#             */
/*   Updated: 2023/03/05 22:50:47 by ahbajaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	n = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * (-1);
	}
	else
		n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	if (n < 10)
		ft_putchar(n + 48);
}

void	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_tprint(va_list ptr, char str)
{
	if (str == 'c')
		ft_putchar(va_arg(ptr, int));
	else if (str == 's')
		ft_putstr(va_arg(ptr, char *));
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(ptr, int));
	else
		ft_putchar(str);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cnt;
	va_list	ptr;

	i = 0;
	cnt = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_tprint(ptr, str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (cnt);
}
