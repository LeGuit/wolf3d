/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:21:22 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/19 13:21:26 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <time.h>

void					rand_map(char *av, t_data *d)
{
	int					i;
	int					j;
	int					randnum;
			
	srand(time(NULL));
	d->ncol = ft_atoi(av);
	d->nrow = d->ncol;
	if (d->ncol == 0)
		error_input();
	malloc_map(d, d->ncol, d->ncol);
	i = 0;
	while (i < d->ncol)
	{
		j = 0;
		while (j < d->ncol)
		{
			randnum = rand() % 100;
			d->map[i][j] = (randnum < DENSITY) ? 1 : 0;
			j++;
		}
		i++;
	}
}
