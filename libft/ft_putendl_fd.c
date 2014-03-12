/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:49:12 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/20 21:13:29 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void		ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
	write(fd, "\n", 1);
}
