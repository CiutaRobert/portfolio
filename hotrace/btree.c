/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:47:38 by fflorens          #+#    #+#             */
/*   Updated: 2013/12/15 22:20:44 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"hotrace.h"

t_btree		*hr_btree_merge(t_btree **node, int ret, char *key, char *value)
{
	t_btree	*new;

	new = hr_btree_new((*node)->key + (*node)->k_len - ret, (*node)->value);
	new->children = (*node)->children;
	(*node)->value = value;
	(*node)->children = new;
	if ((*node)->k_len - ret < hr_strlen(key))
	{
		new->k_len = ret;
		new->neighbours = hr_btree_new(key + (*node)->k_len - ret,
										(*node)->value);
		(*node)->value = NULL;
	}
	(*node)->k_len -= ret;
	return (MERGE);
}

t_btree		*hr_btree_findchild(char *key, char *value, t_btree *node)
{
	int		ret;
	t_btree	*tmp;

	tmp = node;
	while (tmp)
	{
		if ((ret = hr_keycmp(key, tmp->key, tmp->k_len)) == -1 || !ret)
			return (tmp);
		else if (ret > 0)
			return (hr_btree_merge(&tmp, ret, key, value));
		tmp = tmp->neighbours;
	}
	return (tmp);
}

void		hr_btree_add(char *key, char *value, t_btree **node)
{
	t_btree	*child;
	t_btree	*empty;

	if (!*node)
		*node = hr_btree_new(key, value);
	else if (hr_keycmp(key, (*node)->key, (*node)->k_len) == 0)
		(*node)->value = value;
	else
	{
		if ((child = hr_btree_findchild(key + (*node)->k_len, value,
										(*node)->children)) == MERGE)
			return ;
		else if (child)
			hr_btree_add(key + (*node)->k_len, value, &child);
		else if ((empty = (*node)->children))
		{
			while (empty->neighbours)
				empty = empty->neighbours;
			empty->neighbours = hr_btree_new(key + (*node)->k_len, value);
		}
		else
			(*node)->children = hr_btree_new(key + (*node)->k_len, value);
	}
}

char		*hr_btree_search(char *key, t_btree *node)
{
	int		cmp;

	if (!node)
		return (NULL);
	cmp = 1;
	while (cmp)
	{
		cmp = hr_keycmp(key, node->key, node->k_len);
		if (!cmp)
			return (node->value);
		else if (cmp == -42 && node->neighbours)
			node = node->neighbours;
		else if (cmp == -1 && node->children)
		{
			key += node->k_len;
			node = node->children;
		}
		else
			return (NULL);
	}
	return (node->value);
}

t_btree		*hr_btree_new(char *key, char *value)
{
	t_btree	*new;

	if ((new = (t_btree *)malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	new->key = key;
	new->k_len = hr_strlen(key);
	new->value = value;
	new->neighbours = NULL;
	new->children = NULL;
	return (new);
}
