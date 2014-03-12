/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:19:31 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/13 22:09:44 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>

static int		ft_strlen(const char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

void			ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int				puterror(char *str)
{
	write(2, "rtv1: error with ", 19);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
