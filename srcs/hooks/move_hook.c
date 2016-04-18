/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:51:14 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:51:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int				move_fw(t_data *d)
{
	if (!d->map[(int)(d->eye.pos.x + d->eye.dir.x * SPEED)][(int)d->eye.pos.y])
		d->eye.pos.x += d->eye.dir.x * SPEED;
	if (!d->map[(int)d->eye.pos.x][(int)(d->eye.pos.y + d->eye.dir.y * SPEED)])
		d->eye.pos.y += d->eye.dir.y * SPEED;
	return (0);
}

static int				move_bw(t_data *d)
{
	if (!d->map[(int)(d->eye.pos.x - d->eye.dir.x * SPEED)][(int)d->eye.pos.y])
		d->eye.pos.x -= d->eye.dir.x * SPEED;
	if (!d->map[(int)d->eye.pos.x][(int)(d->eye.pos.y - d->eye.dir.y * SPEED)])
		d->eye.pos.y -= d->eye.dir.y * SPEED;
	return (0);
}

static int			straf_rg(t_data *d)
{
	d->eye.pos.x -= d->eye.dir.y * SPEED;
	d->eye.pos.y += d->eye.dir.x * SPEED;
	return (0);
}

static int				straf_lf(t_data *d)
{
	d->eye.pos.x += d->eye.dir.y * SPEED;
	d->eye.pos.y -= d->eye.dir.x * SPEED;
	return (0);
}

int						move_hook(int key, t_data *data)
{
	if (key == W_KEY)
		move_fw(data);
	else if (key == S_KEY)
		move_bw(data);
	else if (key == D_KEY)
		straf_rg(data);
	else if (key == A_KEY)
		straf_lf(data);
	return (0);
}
