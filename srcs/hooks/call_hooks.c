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

static void				key_esc(void)
{
	ft_printf("ESC pressed:\nEXIT SUCCESS");
	exit(0);
}

int						hover_hook(int x, int y, t_data *data)
{
	return (0);
}

int						key_hook(int key, t_data *data)
{
	if (key == ESC)
		key_esc();
	else if (key == W_KEY || key == A_KEY || key == D_KEY || key == S_KEY)
		move_hook(key, data);
	else if (key == LEFT_A || key == RIGHT_A || key == UP_A || key == DOWN_A)
		rot_hook(key, data);
	return (0);
}

int						mouse_hook(int button, int x, int y, void *data)
{
	return (0);
}
