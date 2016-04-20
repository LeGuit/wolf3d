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
#include "mlx.h"

static void				draw_floor(t_data *d, t_vec3i *v)
{
	v->z = FLOOR;
	v->y = 0;
	while (v->y < W_HEIGHT / 2)
	{
		ft_put_pix_to_img(v, &d->mlx->screen);
		v->y++;
	}
}

static void				draw_sky(t_data *d, t_vec3i *v)
{
	v->z = SKY;
	v->y = W_HEIGHT / 2;
	while (v->y < W_HEIGHT)
	{
		ft_put_pix_to_img(v, &d->mlx->screen);
		v->y++;
	}
}

static void				get_color(t_data *d, t_calcul *c, t_ray *r,
						t_vec3i *v)
{
	draw_sky(d, v);
	draw_floor(d, v);
	if (c->hitside == 1)
		v->z = r->raydir.y > 0 ? WEST : EST;
	else
		v->z = r->raydir.x > 0 ? NORTH : SOUTH;
	v->y = c->dstart;
	while (v->y < c->dend)
	{
		ft_put_pix_to_img(v, &d->mlx->screen);
		v->y++;
	}
}

void					draw(t_data *data)
{
	t_ray				ray;
	t_calcul			calcul;
	t_vec3i				v;

	v.x = 0;
	while (v.x < W_WIDTH)
	{
		get_ray(v.x, &ray, data);
		get_calcul(&calcul, &ray);
		get_steps(&calcul, &ray);
		dda(&calcul, data);
		get_normedist(&calcul, &ray);
		get_draw(&calcul);
		get_color(data, &calcul, &ray, &v);
		v.x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->screen.ptr, 0, 0);
}
