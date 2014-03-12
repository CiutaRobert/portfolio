/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynbuf_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:19:09 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/11 17:28:29 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dynbuf.h"

void		dynbuf_del(t_dynbuf **buf)
{
	if (*buf == NULL)
		return ;
	ft_memdel(&((*buf)->ptr));
	ft_memdel((void**)buf);
}
