/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:50:06 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 18:53:35 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_printf.h"

int			nb_len(long int nb, char *base)
{
	int		count;
	int		len;

	len = ft_strlen(base);
	count = (nb <= 0 ? 1 : 0);
	while (nb)
	{
		nb /= len;
		++count;
	}
	return (count);
}

static int	nb_ulen(unsigned long nb, char *base)
{
	int		count;
	int		len;

	len = ft_strlen(base);
	count = (nb == 0 ? 1 : 0);
	while (nb)
	{
		nb /= len;
		++count;
	}
	return (count + 2);
}

void		*ft_memcpy(void *src, size_t size)
{
	char	*dest;
	char	*src_tmp;
	size_t	i;

	if ((dest = malloc(size)) == NULL)
		return (NULL);
	src_tmp = (char *)src;
	i = 0;
	while (i < size)
	{
		dest[i] = src_tmp[i];
		++i;
	}
	return (dest);
}

t_list		*new_elem(void *content, t_type type,
					char *base, t_flag *flag)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = content;
	new->type = type;
	new->base = base;
	new->flag = (t_flag *)ft_memcpy(flag, sizeof(t_flag));
	new->flag_len = flag_length(new);
	new->next = NULL;
	if ((type == CHAR_PTR || type == CHAR_PTRSP) && !new->content)
		new->content = "(null)";
	if (type == INTEGER)
		new->len = nb_len((int)(long int)content, base);
	else if (type == U_INTEGER)
		new->len = nb_len((unsigned int)(long int)content, base);
	else if (type == VOID_PTR)
		new->len = nb_ulen((unsigned long)content, base);
	else if (type == CHAR_PTR)
		new->len = ft_strlen((char *)new->content);
	else if (type == CHAR_PTRSP)
		new->len = ft_strlensp((char *)new->content);
	else if (type == CHAR)
		new->len = 1;
	return (new);
}

void		push_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
}

