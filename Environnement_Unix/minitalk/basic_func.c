/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:39:16 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/08 19:34:47 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		sign;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	nb = 0;
	sign = (str[i] == '-' ? -1 : 1);
	i = (str[i] == '-' || str[i] == '+' ? i : i - 1);
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0') * sign;
	}
	return (nb);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		write(1, "-", 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	c = n + '0';
	write(1, &c, 1);
}

int			ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			ft_putstr(const char *str)
{
	if (!str)
		return (1);
	write(1, str, ft_strlen(str));
	return (1);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
