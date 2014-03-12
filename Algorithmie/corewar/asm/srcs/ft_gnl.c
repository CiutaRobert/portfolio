/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 17:21:49 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 22:35:14 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<unistd.h>
#include			<stdlib.h>
#include			<corewar_asm.h>

static int			gnl_end_line(const int fd, char **line)
{
	int				out;
	char			*eol;
	char			*tmp;

	eol = NULL;
	out = ft_gnl(fd, &eol);
	if (eol)
	{
		tmp = ft_strjoin(*line, eol);
		free(*line);
		free(eol);
		*line = tmp;
		tmp = NULL;
	}
	return (out);
}

static int			gnl_finish_him(int j, int fd, t_lstd **buffer)
{
	t_lstd			*tmp;

	if (j > 0)
		return (j);
	tmp = *buffer;
	while (tmp && ((t_gnl *)tmp->content)->fd != fd)
		tmp = tmp->next;
	free(((t_gnl *)tmp->content)->buffer);
	((t_gnl *)tmp->content)->buffer = NULL;
	free(((t_gnl *)tmp->content));
	tmp->content = NULL;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp == *buffer)
		*buffer = tmp->next;
	free(tmp);
	tmp = NULL;
	return (0);
}

static t_gnl		*gnl_new_buffer(const int fd)
{
	t_gnl			*out;

	if (!(out = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	out->fd = fd;
	out->i = 0;
	if (!(out->buffer = (char *)malloc(BUFF_SIZE + 1)))
		return (NULL);
	out->buffer[0] = 0;
	return (out);
}

static t_gnl		*gnl_get_buffer(const int fd, t_lstd **buffer)
{
	t_gnl			*new;
	t_lstd			*lst;

	if (!*buffer)
	{
		if (!(new = gnl_new_buffer(fd)))
			return (NULL);
		ft_lstadd(buffer, new, LIST_FRONT);
		return (new);
	}
	lst = *buffer;
	while (lst->next && ((t_gnl *)(lst->content))->fd != fd)
		lst = lst->next;
	if (((t_gnl *)(lst->content))->fd == fd)
		return ((t_gnl *)(lst->content));
	if (!(new = gnl_new_buffer(fd)))
		return (NULL);
	ft_lstadd(buffer, new, LIST_FRONT);
	return (new);
}

int					ft_gnl(const int fd, char **line)
{
	static t_lstd	*buff = NULL;
	t_gnl			*cbuff;
	int				j;

	if (fd < 0 || !BUFF_SIZE || !line || !(cbuff = gnl_get_buffer(fd, &buff)))
		return (-1);
	if (!cbuff->buffer[cbuff->i])
	{
		cbuff->i = 0;
		j = read(fd, cbuff->buffer, BUFF_SIZE);
		cbuff->buffer[gnl_finish_him(j, fd, &buff)] = 0;
		if (j <= 0)
			return (j);
	}
	if (!(*line = (char *)malloc(BUFF_SIZE - cbuff->i + 1)))
		return (-1);
	j = 0;
	while (cbuff->buffer[cbuff->i] && cbuff->buffer[cbuff->i] != '\n')
		(*line)[j++] = cbuff->buffer[(cbuff->i)++];
	(*line)[j] = 0;
	if (cbuff->buffer[cbuff->i] == '\n')
		(cbuff->i)++;
	else
		return (gnl_end_line(fd, line));
	return (1);
}
