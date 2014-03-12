/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:15:46 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/30 01:31:54 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Apply setopt function to any char of UNIX basic option arguments.
** It returns an index pointing to the first non-opt argument.
** If all arguments were options, argc is returned.
** The container ptr is passed to setopt as first argument, while the char is
** passed just after (i.e: setopt(container, chr);)
*/
int			ft_optiter(int argc, char **argv,
		int (*setopt)(char, void *), void *container)
{
	int		arg_idx;
	int		chr_idx;

	arg_idx = 1;
	while (arg_idx < argc && argv[arg_idx][0] == '-')
	{
		if (ft_strcmp(argv[arg_idx], "-") == 0)
			return (arg_idx);
		if (ft_strcmp(argv[arg_idx], "--") == 0)
			return (arg_idx + 1);
		chr_idx = 1;
		while (argv[arg_idx][chr_idx] != '\0')
		{
			if ((setopt(argv[arg_idx][chr_idx], container)) == -1)
				return (-1);
			chr_idx++;
		}
		arg_idx++;
	}
	return (arg_idx);
}
