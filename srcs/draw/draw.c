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

void				draw(t_data *data)
{
	t_ray			ray;
	t_calcul		calcul;

	while (x < W_WIDTH)
	{
		get_ray(x, &ray, data);
		get_calcul(&calcul, &ray);
		get_steps(&calcul, &ray);
		dda(&calcul, data);
		get_normedist(&calcul, &ray);
		if (calcul.hitside == 0)
			nwdist = calcul.map.x - ray.raypos.x +
			(1 - calcul.step.x) / 2) / ray.raydir.x;
		else
			nwdist = calcul.map.y - ray.raypos.y + (1 - calcul.step.y) / 2) / ray.raydir.y;
		x++;
	}
}