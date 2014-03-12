/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:19:10 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 17:01:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

static int	ft_lstlastelem(t_list **idx, int index)
{
	int		new_index;
	t_list	*tmp;

	new_index = 0;
	tmp = *idx;
	while (tmp && index--)
	{
		*idx = tmp;
		tmp = tmp->next;
		++new_index;
	}
	return (new_index);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new_list;
	t_list	*idx;
	int		index;

	new_list = NULL;
	idx = lst;
	index = ft_lstlastelem(&idx, -1);
	while (--index >= 0)
	{
		if ((tmp = ft_lstnew(idx->content, idx->content_size)) == NULL)
			return (NULL);
		tmp = f(tmp);
		ft_lstadd(&new_list, tmp);
		idx = lst;
		ft_lstlastelem(&idx, index);
	}
	return (new_list);
}
