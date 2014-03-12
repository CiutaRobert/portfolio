/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:58:42 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 19:00:06 by gabtoubl         ###   ########.fr       */
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

int			ft_strlensp(const char *str)
{
	int		i;
	int		len;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > 126)
			len += 3;
		++len;
	}
	return (len);
}

void		ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void		ft_putprintf(const char *strout, int len)
{
	if (!strout)
		return ;
	write(1, strout, len);
}
