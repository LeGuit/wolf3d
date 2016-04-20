/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:06:44 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/20 17:06:46 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define SCALE 5

static void				draw_square(t_vec3i *v, t_data *d)
{
	t_vec3i	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < SCALE)
	{
		j = 0;
		while (j < SCALE)
		{
			tmp = (t_vec3i){20 + v->x * SCALE + i, 20 + v->y * SCALE + j, v->z};

			ft_put_pix_to_img(&tmp, &d->mlx->screen);
			j++;
		}
		i++;
	}
}



static void				draw_minimap(t_data *d)
{
	t_vec3i				v;

	v.y = 0;
	while (v.y < d->nrow)
	{
		v.x = 0;
		while (v.x < d->ncol)
		{
			if (d->map[d->nrow - 1 - v.y][v.x] == 1)
				v.z = 0x000000;
			else
				v.z = 0xffffff;
			draw_square(&v, d);
			v.x++;
		}
		v.y++;
	}
	v = (t_vec3i){(int)d->eye.pos.y, d->nrow - 1 - (int)d->eye.pos.x, 0xff0000};
	draw_square(&v, d);
}

void					minimap(t_data *d)
{
	if (d->minimapflag == 0)
		return ;
	draw_minimap(d);
}
