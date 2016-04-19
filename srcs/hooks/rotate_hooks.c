/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:51:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:51:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "math.h"

static int				rot_lf(t_data *d)
{
	double				tmp;

	tmp = d->eye.dir.x;
	d->eye.dir.x = d->eye.dir.x * cos(SPEED) - d->eye.dir.y * sin(SPEED);
	d->eye.dir.y = tmp * sin(SPEED) + d->eye.dir.y * cos(SPEED);
	tmp = d->eye.plane.x;
	d->eye.plane.x = d->eye.plane.x * cos(SPEED)
		- d->eye.plane.y * sin(SPEED);
	d->eye.plane.y = tmp * sin(SPEED) + d->eye.plane.y * cos(SPEED);
	return (0);
}

static int				rot_rg(t_data *d)
{
	double				tmp;

	tmp = d->eye.dir.x;
	d->eye.dir.x = d->eye.dir.x * cos(-SPEED) - d->eye.dir.y * sin(-SPEED);
	d->eye.dir.y = tmp * sin(-SPEED) + d->eye.dir.y * cos(-SPEED);
	tmp = d->eye.plane.x;
	d->eye.plane.x = d->eye.plane.x * cos(-SPEED)
		- d->eye.plane.y * sin(-SPEED);
	d->eye.plane.y = tmp * sin(-SPEED) + d->eye.plane.y * cos(-SPEED);
	return (0);
}

int						rot_hook(int key, t_data *data)
{
	if (key == LEFT_A)
		rot_lf(data);
	else if (key == RIGHT_A)
		rot_rg(data);
	return (0);
}
