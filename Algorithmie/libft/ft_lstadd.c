/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 23:03:06 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 17:32:44 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>
#include	"libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !*alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
