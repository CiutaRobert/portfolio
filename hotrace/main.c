/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:47:43 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 23:11:30 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"hotrace.h"

static void	search_keyword(char **key, t_btree *root)
{
	char	*value;

	if ((value = hr_btree_search(*key, root)))
		hr_putendl(value);
	else
	{
		hr_putstr(*key);
		hr_putendl(": Not found.");
	}
	if (*key)
		free(*key);
	*key = NULL;
}

int			main(void)
{
	char	*line;
	char	*line2;
	int		line_nb;
	int		is_end;
	t_btree	*root;

	root = hr_btree_new((char*) "", NULL);
	is_end = 0;
	line2 = NULL;
	line_nb = -1;
	while (hr_gnl(0, &line) && ++line_nb >= 0)
	{
		if (is_end)
			search_keyword(&line, root->children);
		if (!line || !line[0])
			is_end = 1;
		if (!(line_nb % 2))
			line2 = line;
		if (line_nb % 2 && !is_end)
			hr_btree_add(line2, line, &root);
	}
	if (line)
		search_keyword(&line, root->children);
	return (0);
}
