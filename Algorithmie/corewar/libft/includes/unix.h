/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 20:20:19 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 20:20:42 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_H
# define UNIX_H

/*
** File access and permissions (from standards)
*/
# define E_NOENT	"No such file or directory"
# define E_ACCES	"Permission denied"
# define E_EXIST	"File exists"
# define E_NOTDIR	"Not a directory"
# define E_ISDIR	"Is a directory"
# define E_2BIG		"Argument list too long"

/*
** Misc system related errors (from standards)
*/
# define E_NOMEM	"Cannot allocate memory"
# define E_INVAL	"Invalid argument"
# define E_BADF		"Bad file descriptor"
# define E_BUSY		"Device or ressource busy"
# define E_AGAIN	"Ressource temporarily unavailable"
# define E_IO		"Inuput/output error"

#endif /* !UNIX_H */
