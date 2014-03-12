/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:23:05 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/15 00:46:11 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<math.h>
#include	"rtv1.h"

static void	rot_x(t_xyz *xyz, t_xyz *rot, int invert)
{
	t_xyz	new_xyz;

	new_xyz.y = xyz->y * cos(invert * rot->x)
		+ xyz->z * -sin(invert * rot->x);
	new_xyz.z = xyz->y * sin(invert * rot->x)
		+ xyz->z * cos(invert * rot->x);
	xyz->y = new_xyz.y;
	xyz->z = new_xyz.z;
}

static void	rot_y(t_xyz *xyz, t_xyz *rot, int invert)
{
	t_xyz	new_xyz;

	new_xyz.x = xyz->x * cos(invert * rot->y)
		+ xyz->z * sin(invert * rot->y);
	new_xyz.z = xyz->x * -sin(invert * rot->y)
		+ xyz->z * cos(invert * rot->y);
	xyz->x = new_xyz.x;
	xyz->z = new_xyz.z;
}

static void	rot_z(t_xyz *xyz, t_xyz *rot, int invert)
{
	t_xyz	new_xyz;

	new_xyz.x = xyz->x * cos(invert * rot->z)
		+ xyz->y * -sin(invert * rot->z);
	new_xyz.y = xyz->x * sin(invert * rot->z)
		+ xyz->y * cos(invert * rot->z);
	xyz->x = new_xyz.x;
	xyz->y = new_xyz.y;
}

void		all_rot(t_xyz *xyz, t_xyz *rot, int invert)
{
	if (invert == -1)
	{
		rot_x(xyz, rot, invert);
		rot_y(xyz, rot, invert);
		rot_z(xyz, rot, invert);
	}
	else
	{
		rot_z(xyz, rot, invert);
		rot_y(xyz, rot, invert);
		rot_x(xyz, rot, invert);
	}
}
