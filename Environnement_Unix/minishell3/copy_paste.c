/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 02:16:46 by cvxfous           #+#    #+#             */
/*   Updated: 2014/02/07 15:08:30 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_sh.h"

void		cut_line(t_all *all)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(all->line);
	j = 0;
	while (j < BUFF_SIZE)
		all->save[j++] = 0;
	i = all->cursor_x - 1;
	j = -1;
	while (++i < len)
	{
		all->save[++j] = all->line[i];
		all->line[i] = 0;
	}
	reprint_line(all);
}

void		paste_line(t_all *all)
{
	int		i;

	i = -1;
	while (all->save[++i] && i < BUFF_SIZE)
		insert_char(all, all->save[i]);
}
