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

static void				correct_map(t_data *d)
{
	int					i;
	int					j;

	i = 0;
	while (i < d->nrow)
	{
		d->map[i][0] = 1;
		d->map[i][d->ncol - 1] = 1;
		i++;
	}
	j = 0;
	while (j < d->ncol)
	{
		d->map[0][j] = 1;
		d->map[d->nrow - 1][j] = 1;
		j++;

	}
}

static void				get_start(t_data *d)
{
	int					i;
	int					j;

	d->eye.dir.x = -1;
	d->eye.dir.y = 0;
	d->eye.plane.x = 0;
	d->eye.plane.y = 0.66;
	i = 1;
	while (i < d->nrow)
	{
		j = 1;
		while (j < d->ncol)
		{
			if (d->map[i][j] == 0)
			{
				d->eye.pos.x = j + 0.5;
				d->eye.pos.y = i + 0.5;
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
	d->minimapflag = 0;
}

int						main(int ac, char **av)
{
	t_data				data;

	if (ac != 2)
		error_input();
	init_data(&data);
	get_map(av[1], &data);
	correct_map(&data);
	print_map(&data);
	get_start(&data);
	mlx_start(&data);
	return (0);
}
