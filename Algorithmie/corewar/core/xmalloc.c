/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:50:22 by jzak              #+#    #+#             */
/*   Updated: 2014/01/18 15:50:39 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		*ft_xmalloc_catch(void *ptr)
{
	return (ptr);
}

void		ft_xmalloc_error(void)
{
	error(NULL, "malloc failed\n");
}
