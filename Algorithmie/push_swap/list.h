/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 01:29:26 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 13:41:12 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				LIST_H
# define			LIST_H
typedef struct		s_elem
{
	int				val;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;
typedef struct		s_list
{
	void			(*push_back)(void *, int);
	void			(*push_front)(void *, int);
	void			(*pop)(void *);
	void			(*shift)(void *);
	t_elem			*elems;
}					t_list;
t_list				*create_list(void);
#endif				/* !LIST_H */
