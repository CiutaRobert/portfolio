/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 20:56:03 by jzak              #+#    #+#             */
/*   Updated: 2014/01/31 22:10:44 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"

static t_opt_elem	*get_opt(t_opt_elem *opt, const char *str)
{
	while (opt != NULL)
	{
		if (ft_strcmp(opt->name, str) == 0)
			return (opt);
		opt = opt->next;
	}
	return (NULL);
}

/*
** TODO : add -- option
*/
void				exec_opt(t_opt *opt, char *str, void *data)
{
	t_uint		i;
	t_opt_elem	*curr;
	int			nbr;

	i = 1;
	if ((curr = get_opt(opt->elem, str)) == NULL)
		error(opt->help, "illegal option -- %s\n", str);
	opt->i++;
	nbr = curr->nbr_val - 1;
	opt->value[0] = str;
	while (i < curr->nbr_val && opt->i < opt->ac)
	{
		if (opt->av[opt->i][0] == '-' && opt->av[opt->i][1] != '\0')
			error(opt->help, "illegal option -- %s\n", &opt->av[opt->i][1]);
		opt->value[i] = opt->av[opt->i];
		++i;
		opt->i++;
	}
	if (i != curr->nbr_val)
		error(opt->help, "expect %d argument(s) for option %s\n", nbr, str);
	curr->fn(opt->value, curr->nbr_val, data);
}

void				parse_opt(t_opt *opt, void *data)
{
	opt->value = secure_calloc(sizeof(char*) * (opt->max_opt));
	while (opt->i < opt->ac)
	{
		if (opt->av[opt->i][0] == '-' && opt->av[opt->i][1] != '\0')
			exec_opt(opt, &opt->av[opt->i][1], data);
		else
		{
			opt->value[0] = "";
			opt->value[1] = opt->av[opt->i];
			opt->def->fn(opt->value, opt->def->nbr_val, data);
			++opt->i;
		}
	}
	ft_memdel((void**)&opt->value);
}
