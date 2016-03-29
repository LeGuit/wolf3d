/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:06:33 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 17:06:49 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			get_ray(int x, t_ray *ray)
{
	ray->camera = 2 * x / (double)W_WIDTH - 1;
	ray->raypos = (t_vec2d)data->pos;
	ray->raydir.x = data->dir.x + data->plane.x * ray->camera;
	ray->raydir.y = data->dir.y + data->plane.y * ray->camera;
}

static void			get_calcul(t_calcul *c, t_ray *r)
{
	c->map.x = (int)r->raypos.x;
	c->map.y = (int)r->raypos.y;
	c->side.x = sqrt(1 + pow(r->dir.y, 2) / pow(r->dir.x, 2));
	c->side.x = sqrt(1 + pow(r->dir.x, 2) / pow(r->dir.y, 2));
}

void				draw(t_data *data)
{
	t_ray			ray;
	t_calcul		calcul;

	while (x < W_WIDTH)
	{
		get_ray(x, &ray, data);
		get_calcul(&calcul, &ray)
		x++;
	}
}