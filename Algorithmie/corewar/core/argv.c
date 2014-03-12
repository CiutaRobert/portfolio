/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 20:16:18 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 22:27:13 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"

t_opt		*init_opt(t_opt_fn def, int ac, char **av, t_helpfn help)
{
	t_opt		*opt;
	t_opt_elem	*new;

	new = secure_malloc(sizeof(*new));
	new->name = NULL;
	new->nbr_val = 2;
	new->fn = def;
	opt = secure_malloc(sizeof(*opt));
	opt->elem = NULL;
	opt->def = new;
	opt->help = help;
	opt->ac = ac;
	opt->av = av;
	opt->value = NULL;
	opt->i = 1;
	opt->max_opt = 2;
	return (opt);
}

void		add_opt(t_opt *opt, const char *name, t_uint nbr_val, t_opt_fn fn)
{
	t_opt_elem	*new;

	new = secure_malloc(sizeof(*new));
	new->name = name;
	new->nbr_val = nbr_val + 1;
	new->fn = fn;
	new->next = opt->elem;
	opt->elem = new;
	if (opt->max_opt < new->nbr_val)
		opt->max_opt = new->nbr_val;
}

void		destroy_opt(t_opt **opt)
{
	t_opt_elem	*elem;
	t_opt_elem	*tmp;

	elem = (*opt)->elem;
	while (elem)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
	free((*opt)->value);
	free((*opt)->def);
	ft_memdel((void**)opt);
}
