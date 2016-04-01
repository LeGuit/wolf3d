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

// static void				get_color(t_data *d, t_calcul *c, t_vec3i *v)
// {
// 	v->z = NORTH;
// 	v->y = c->dstart;
// 	while (v->y < c->dend)
// 	{
// 		ft_put_pix_to_img(v, &d->mlx->screen);
// 		v->y++;
// 	}
// }


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
		// get_color(data, &calcul, &v);
		v.z = NORTH;
		v.y = calcul.dstart;
		while (v.y < calcul.dend)
		{
			ft_put_pix_to_img(&v, &data->mlx->screen);
			v.y++;
		}
		v.x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
				data->mlx->screen.ptr, 0, 0);
}
