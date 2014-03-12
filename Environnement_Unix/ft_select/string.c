/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:01:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:01:35 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_select.h"

int			ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			ft_putchar2(int c)
{
	write(g_all.fd, &c, 1);
	return (1);
}

void		ft_putstr_fd(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void		*puterror(const char *str)
{
	write(2, "ft_select: Error with ", 22);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (NULL);
}
