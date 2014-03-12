/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:49:25 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:10:28 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove blanks (\n, \t, space) on the left of the given string
*/
char	*ft_strltrim(char const *s)
{
	while (*s == 9 || *s == 10 || *s == 32)
		s++;
	return (ft_strdup(s));
}
