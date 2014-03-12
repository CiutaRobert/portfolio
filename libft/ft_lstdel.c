/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:17:12 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 17:32:14 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>
#include			"libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*tmp;
	t_list			*tmp2;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2->next;
	}
	*alst = NULL;
}
