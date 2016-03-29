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

static void				init_texture(t_data *data)
{
	data->texture[0] = NORTH;
	data->texture[1] = SOUTH;
	data->texture[2] = EST;
	data->texture[3] = WEST;
	// data->texture[4] = FLOOR;
	// data->texture[5] = SKY;
}

static void				init_data(t_data *data)
{
	data->eye.pos.x = 22;
	data->eye.pos.y = 12;
	data->eye.dir.x = -1;
	data->eye.pos.x = 22;
	data->eye.plane.x = 0;
	data->eye.plane.x = 0.66;

	init_texture(data);
}

int						main(int ac, char **av)
{
	t_data				data;

	(void)av;
	if (ac != 1)
		error_input();
	init_data(&data);
	mlx_start(&data);
	return (0);
}
