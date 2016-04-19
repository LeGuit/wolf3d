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
#include <stdio.h>
static void				get_start(t_data *d)
{
	int					i;
	int					j;

	d->eye.dir.x = 1;
	d->eye.dir.y = 0;
	d->eye.plane.x = 0;
	d->eye.plane.y = 0.66;
	i = 1;
	while (i < d->ncol)
	{
		j = 1;
		while (j < d->ncol)
		{
			ft_printf("i: %d j: %d map: %d\n", i, j, d->map[i][j]);
			if (d->map[i][j] == 0)
			{
				d->eye.pos.x = (double)i;
				d->eye.pos.y = (double)j;
				printf("x: %f y: %f\n", d->eye.pos.x, d->eye.pos.y);
				return ;
			}
			j++;
		}
		i++;
	}
}

static void				init_data(t_data *d)
{
	d->ncol = 0;
	d->nrow = 0;
	d->flag = 0;
}

int						main(int ac, char **av)
{
	t_data				data;

	if (ac != 2)
		error_input();
	init_data(&data);
	get_map(av[1], &data);
	get_start(&data);
	mlx_start(&data);
	return (0);
}
