/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:52:13 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:52:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void				init_texture(t_data *d)
{
	d->texture[0] = NORTH;
	d->texture[1] = SOUTH;
	d->texture[2] = EST;
	d->texture[3] = WEST;
	// d->texture[4] = FLOOR;
	// d->texture[5] = SKY;
}

static void				init_data(t_data *d)
{
	d->eye.pos.x = 22;
	d->eye.pos.y = 12;
	ft_printf("%d %d\n", d->eye.pos.x, d->eye.pos.y);
	
	d->eye.dir.x = -1;
	d->eye.dir.y = 0;
	d->eye.plane.x = 0;
	d->eye.plane.y = 0.66;
	d->ncol = 0;
	d->nrow = 0;
	d->flag = 0;
	init_texture(d);
}

int						main(int ac, char **av)
{
	t_data				data;

	if (ac != 2)
		error_input();
	init_data(&data);
	get_map(av[1], &data);
	mlx_start(&data);
	return (0);
}
