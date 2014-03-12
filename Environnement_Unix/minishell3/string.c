/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:01:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 02:03:29 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_sh.h"

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

int			ft_putchar(int c)
{
	write(1, &c, 1);
	return (OK);
}

void		ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

int			puterror(const char *str)
{
	write(2, "ft_select: Error with ", 22);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (NOT_OK);
}
