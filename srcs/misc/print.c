/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:57:07 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/04/20 15:57:08 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					print_map(t_data *d)
{
	int					i;
	int					j;

	i = 0;
	while (i < d->nrow)
	{
		j = 0;
		while (j < d->ncol)
		{
			ft_printf("%d ", d->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}