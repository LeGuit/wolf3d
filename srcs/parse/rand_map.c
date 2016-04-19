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

void					rand_map(char *av, t_data *d)
{
	int					i;
	int					j;
	int					randnum;

	d->ncol = ft_atoi(av);
	if (d->ncol == 0)
		error_input();
	malloc_map(d, d->ncol);
	i = 0;
	while (i < d->ncol)
	{
		j = 0;
		while (j < d->ncol)
		{
			randnum = rand() % 3;
			d->map[i][j] = randnum ? randnum - 1 : randnum;
			j++;
		}
		i++;
	}
}
