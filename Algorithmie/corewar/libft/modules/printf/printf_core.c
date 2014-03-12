/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:41:57 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:44:27 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_ptf_type		*types_list(void)
{
	static t_ptf_type		types[] = {
		{ 's', (t_ptf_type_fn)ptf_type_s },
		{ 'c', (t_ptf_type_fn)ptf_type_c },
		{ 'i', (t_ptf_type_fn)ptf_type_d },
		{ 'd', (t_ptf_type_fn)ptf_type_d },
		{ 'D', (t_ptf_type_fn)ptf_type_D },
		{ 'u', (t_ptf_type_fn)ptf_type_u },
		{ 'U', (t_ptf_type_fn)ptf_type_U },
		{ 'x', (t_ptf_type_fn)ptf_type_x },
		{ 'X', (t_ptf_type_fn)ptf_type_X },
		{ 'o', (t_ptf_type_fn)ptf_type_o },
		{ 'O', (t_ptf_type_fn)ptf_type_O },
		{ 'p', (t_ptf_type_fn)ptf_type_p },
		{ '%', (t_ptf_type_fn)ptf_type_perc },
		{ '\0', NULL }
	};

	return (types);
}

static t_ptf_type_fn	get_type_fn(char label)
{
	int						i;
	t_ptf_type				*types;

	types = types_list();
	i = 0;
	while (types[i].label != '\0')
	{
		if (types[i].label == label)
			return (types[i].function);
		i++;
	}
	return (NULL);
}

static int				get_flags_len(int *len, int *zero, char **s, va_list ap)
{
	if (**s == '.')
		(*s) += 1;
	if (**s == '0')
	{
		(*s) += 1;
		*zero = 1;
	}
	if (**s == '*')
	{
		(*s) += 1;
		return ((*len = va_arg(ap, int)));
	}
	if (**s != '-' && (**s < '1' || **s > '9'))
		return (0);
	*len = ft_atoi(*s);
	(*s) += ft_intlen(*len);
	return (*len);
}

static t_ptf_flags		get_flags(char *s, va_list ap)
{
	t_ptf_flags				f;

	f.length = 0;
	f.length_zero = 0;
	f.precision = 0;
	f.precision_zero = 0;
	f.tags = ft_strnew(ft_strlen(s));
	while (*s != '.' && *s != '\0')
	{
		if (IS_NBR(*s))
			get_flags_len(&f.length, &f.length_zero, &s, ap);
		else
			f.tags[ft_strlen(f.tags)] = *s++;
	}
	while (*s != '\0')
	{
		if (IS_NBR(*s))
			get_flags_len(&f.precision, &f.precision_zero, &s, ap);
		else
			f.tags[ft_strlen(f.tags)] = *s++;
	}
	return (f);
}

void					ptf_putarg(t_dynbuf *buf, const char **astr, va_list ap)
{
	char					*str;
	int						s;
	t_ptf_type_fn			type_fn;

	str = ft_strdup(*astr);
	s = 0;
	while (IS_FLAG(str[s]))
	{
		if ((type_fn = get_type_fn(str[s])) != NULL)
		{
			str[s] = '\0';
			dynbuf_write(buf, type_fn(get_flags(str, ap), ap), -1);
			(*astr)++;
			return (ft_strdel(&str));
		}
		(*astr)++;
		s++;
	}
	if (str[s] == '\0')
		return (ft_strdel(&str));
	dynbuf_write(buf, &(str[s]), 1);
	(*astr)++;
	return (ft_strdel(&str));
}
