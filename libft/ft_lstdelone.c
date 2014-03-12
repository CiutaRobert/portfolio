/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:21:55 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 17:32:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>
#include			"libft.h"

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
