/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 21:19:42 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:46:09 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		"rtv1.h"

t_obj			*obj_new(t_type type, t_xyz pos, t_xyz rot, u_int color)
{
	t_obj		*new;

	if ((new = (t_obj *)malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	new->type = type;
	new->pos = pos;
	new->rot = rot;
	new->color = color;
	new->next = NULL;
	return (new);
}

void			obj_pushback(t_obj **objs, t_obj *new)
{
	t_obj		*tmp;

	if (!*objs)
		*objs = new;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
