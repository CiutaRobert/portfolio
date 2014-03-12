/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:48:28 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/20 20:48:47 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void		ft_putstr_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}
