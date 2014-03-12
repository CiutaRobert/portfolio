/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:28:18 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/15 21:05:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"hotrace.h"

int			hr_keycmp(char *key1, char *key2, int k_len)
{
	int		cur;

	cur = -1;
	while (++cur < k_len && *key1 == *key2 && *key1)
	{
		key1++;
		key2++;
	}
	if (!cur)
		return (-42);
	if ((*key1 && !*key2) || (*key1 && k_len - cur == 0))
		return (-1);
	if (!*key1 && k_len - cur == 0)
		return (0);
	return (k_len - cur);
}
