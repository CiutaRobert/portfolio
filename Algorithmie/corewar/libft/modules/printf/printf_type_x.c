/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:33 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:42:38 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ptf_type_p(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = ft_strnew(sizeof(long) + 2);
	ft_strcat(res, "0x");
	ft_strcat((res + 2), ft_ltobase(va_arg(ap, unsigned long), 16));
	return (res);
}

char			*ptf_type_O(t_ptf_flags f, va_list ap)
{
	char		*res;

	(void)f;
	res = ft_ltobase(va_arg(ap, unsigned long), 8);
	ptf_fmt_int(&f, &res);
	return (res);
}

char			*ptf_type_o(t_ptf_flags f, va_list ap)
{
	char		*res;

	if (TAG(f, 'l'))
		return (ptf_type_O(f, ap));
	res = ft_itobase(va_arg(ap, unsigned int), 8);
	if (TAG(f, '#'))
		res = ft_strjoin("0", res);
	ptf_fmt_int(&f, &res);
	return (res);
}

char			*ptf_type_X(t_ptf_flags f, va_list ap)
{
	char		*res;
	int			i;

	res = ptf_type_x(f, ap);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = (char)ft_toupper((int)res[i]);
		i++;
	}
	ptf_fmt_int(&f, &res);
	return (res);
}

char			*ptf_type_x(t_ptf_flags f, va_list ap)
{
	char		*res;

	if (TAG(f, 'l'))
		res = ft_ltobase(va_arg(ap, unsigned long), 16);
	else
		res = ft_itobase(va_arg(ap, unsigned int), 16);
	if (TAG(f, '#'))
		res = ft_strjoin("0x", res);
	ptf_fmt_int(&f, &res);
	return (res);
}
