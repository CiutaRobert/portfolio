/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:48:56 by cvxfous           #+#    #+#             */
/*   Updated: 2014/02/09 02:29:54 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

int			send_exit(t_all *all)
{
	all->line[0] = 'e';
	all->line[1] = 'x';
	all->line[2] = 'i';
	all->line[3] = 't';
	all->line[4] = 0;
	go_end(all);
	reprint_line(all);
	return (SEND_LINE);
}
