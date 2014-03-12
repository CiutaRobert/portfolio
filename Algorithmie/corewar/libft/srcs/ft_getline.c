/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:29:50 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/03 12:39:43 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Find the characther '\n' in find
** return the new line found in find
** and stock the rest of find buffer in stock
*/
static int		update_stock(char **stock, char **eol)
{
	**eol = '\0';
	ft_strdel(stock);
	*stock = ft_strdup(*eol + 1);
	return (1);
}

/*
** Read GETLINE_BUFF_SIZE characther, and put the result in *line
*/
static int		terminate_line(int const fd, char **line, char **stock)
{
	size_t		ret;
	size_t		line_len;
	char		*eol;

	ret = GETLINE_BUFF_SIZE;
	while (ret == GETLINE_BUFF_SIZE)
	{
		line_len = (*line == NULL ? 0 : ft_strlen(*line));
		*line = ft_realloc(*line, line_len, (line_len + GETLINE_BUFF_SIZE + 1));
		if ((ret = read(fd, ((*line) + line_len), GETLINE_BUFF_SIZE)) < 1)
			return (ret);
		if ((eol = ft_strchr(*line, '\n')) != NULL)
			return (update_stock(stock, &eol));
	}
	ft_strdel(stock);
	return (1);
}

/*
** Get next line in the file descriptor fd
*/
int				ft_getline(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*eol;
	int				ret;

	if (line == NULL || fd < 0 || GETLINE_BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (stock != NULL && *stock != '\0')
	{
		ft_strdup(stock);
		if ((eol = ft_strchr(*line, '\n')) != NULL)
			return (update_stock(&stock, &eol));
	}
	ret = terminate_line(fd, line, &stock);
	if (ret == 0 && stock != NULL && *stock != '\0')
	{
		*line = ft_strdup(stock);
		ft_strdel(&stock);
		return (1);
	}
	return (ret);
}
