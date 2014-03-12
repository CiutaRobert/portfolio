/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 00:32:31 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/21 00:43:15 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *s, size_t n)
{
	char		*data;
	char		swap;
	size_t		begin;
	size_t		end;

	if (n == 0)
		return ;
	data = (char*)s;
	begin = 0;
	end = n - 1;
	while (begin < end)
	{
		swap = data[begin];
		data[begin] = data[end];
		data[end] = swap;
		end--;
		begin++;
	}
}
