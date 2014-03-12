/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 03:13:37 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 04:18:36 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_sh.h"

t_list		*lst_new(char *str)
{
	t_list	*new;

	if ((new = malloc(sizeof(*new))) == NULL
		|| (new->str = malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	new->str = ft_strcpy(str, new->str);
	new->str[ft_strlen(str)] = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		lst_pushback(t_list **list, char *str)
{
	t_list	*new;
	t_list	*tmp;

	new = lst_new(str);
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
