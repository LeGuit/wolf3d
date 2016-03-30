/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:25:30 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/30 12:25:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "math.h"

void					get_ray(int x, t_ray *r, t_data *d)
{
	r->camera = 2 * x / (double)W_WIDTH - 1;
	r->raypos = (t_vec2d)d->eye.pos;
	r->raydir.x = d->eye.dir.x + d->eye.plane.x * r->camera;
	r->raydir.y = d->eye.dir.y + d->eye.plane.y * r->camera;
}

void					get_calcul(t_calcul *c, t_ray *r)
{
	c->map.x = (int)r->raypos.x;
	c->map.y = (int)r->raypos.y;
	c->delta.x = sqrt(1 + pow(r->raydir.y, 2) / pow(r->raydir.x, 2));
	c->delta.y = sqrt(1 + pow(r->raydir.x, 2) / pow(r->raydir.y, 2));
	c->hit = 0;
}

void					get_steps(t_calcul *c, t_ray *r)
{
	if (r->raydir.x < 0)
		c->side.x = (r->raypos.x - c->map.x) * c->delta.x;
	else
		c->side.x = (c->map.x + 1.0 - r->raypos.x) * c->delta.x;
	c->step.x = r->raydir.x < 0 ? -1 : 1;
	if (r->raydir.y < 0)
		c->side.y = (r->raypos.y - c->map.y) * c->delta.y;
	else
		c->side.y = (c->map.y + 1.0 - r->raypos.y) * c->delta.y;
	c->step.y = r->raydir.y < 0 ? -1 : 1;
}

void					get_normedist(t_calcul *c, t_ray *r)
{
	if (c->hitside == 0)
		c->nwdist = (c->map.x - r->raypos.x +
		(1 - c->step.x) / 2) / r->raydir.x;
	else
		c->nwdist = (c->map.y - r->raypos.y +
		(1 - c->step.y) / 2) / r->raydir.y;
}

void					get_draw(t_calcul *c)
{
	c->lheight = (int)(W_HEIGHT / c->nwdist);
	c->dstart = -c->lheight / 2 + W_HEIGHT / 2;
	if (c->dstart < 0)
		c->dstart = 0;
	c->dend = c->lheight / 2 + W_HEIGHT / 2;
	if (c->dend < 0)
		c->dend = W_HEIGHT - 1;
}
