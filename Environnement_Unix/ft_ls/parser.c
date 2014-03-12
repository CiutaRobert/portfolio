/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:59:50 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/12 22:24:47 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

static int	get_opt(char *opt, char *str)
{
	char	optdone[OPTDONE] = "alrtR";
	int		i;
	int		is_ok;

	while (*++str)
	{
		i = -1;
		is_ok = 0;
		while (++i < OPTDONE)
		{
			if (optdone[i] == *str)
			{
				opt[i] = ON;
				is_ok = 1;
			}
		}
		if (!is_ok)
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(*str);
			ft_putstr("\nusage: ./ft_ls [-Ralrt] [file ...]\n");
			return (0);
		}
	}
	return (1);
}

int			parse_arg(int ac, char **av, char *opt)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			if (!ft_strcmp("--", av[i]))
				return (i + 1);
			if (get_opt(opt, av[i]) == 0)
				return (-42);
		}
		else
			return (i);
		++i;
	}
	return (-1);
}

void		set_all_off(char *opt)
{
	int		i;

	i = -1;
	while (++i < OPTDONE)
		opt[i] = OFF;
}
