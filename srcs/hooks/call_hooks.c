/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:49:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:49:04 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void				key_esc(void)
{
	ft_printf("ESC pressed:\nEXIT SUCCESS\n");
	exit(0);
}

// int						key_pressed(int key, t_data *data)
// {
// 	if (key == A_KEY)
// 		flag |= A_SET;
// 	else if (key == D_KEY)
// 		flag |= D_SET;
// 	else if (key == S_KEY)
// 		flag |= S_SET;
// 	else if (key == W_KEY)
// 		flag |= W_S;
// 	else if (key == LEFT_KEY)
// 		flag |= S_KEY;
// 	else if (key == S_KEY)
// 		flag |= S_KEY;

// }

// int						key_released(int key, t_data *data)
// {
// 	data->flag = 0;
// 	key_hook(key, data);
// }

int						key_hook(int key, t_data *d)
{
	if (key == ESC)
		key_esc();
	else if (key == W_KEY || key == A_KEY || key == D_KEY || key == S_KEY)
		move_hook(key, d);
	else if (key == LEFT_A || key == RIGHT_A)
		rot_hook(key, d);
	if (key == UP_A)
	{
		if (d->minimapflag == 0)
			d->minimapflag = 1;
		else if (d->minimapflag == 1)
			d->minimapflag = 0;
		minimap(d);
	}
	return (0);
}
