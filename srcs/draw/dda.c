/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:34:33 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 18:34:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					dda(t_calcul *c, t_data *d)
{
	while (c->hit == 0)
	{
		if (c->side.x < c->side.y)
		{
			c->side.x += c->delta.x;
			c->map.x += c->step.x;
			c->hitside = 0;
		}
		else
		{
			c->side.y += c->delta.y;
			c->map.y += c->step.y;
			c->hitside = 1;
		}
		if (d->map[c->map.x][c->map.y] > 0)
			c->hit = 1;
	}
}
