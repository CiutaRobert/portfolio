/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/30 13:49:15 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int			free_tab(char **tab, int ret)
{
	int		i;

	if (!tab)
		return (ret);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (ret);
}
