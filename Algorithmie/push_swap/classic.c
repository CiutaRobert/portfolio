/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 01:49:47 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/25 03:06:48 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int			ft_strlen(const char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}

void		ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void		ft_putnbr(int n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		write(1, "-", 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	n += '0';
	write(1, &n, 1);
}

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
