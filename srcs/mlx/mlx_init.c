/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:52:22 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:52:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "mlx.h"

static int				ft_mlx_image_init(void *mlx_ptr, t_image *image,
						int width, int height)
{
	image->ptr = mlx_new_image(mlx_ptr, width, height);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line,
									&image->endian);
	image->width = width;
	image->height = height;
	return (0);
}

int						wolf_loop(t_data *data)
{
	ft_bzero(data->mlx->screen.data, data->mlx->screen.width
		* data->mlx->screen.height * 4);
	draw(data);
	return (0);
}

void					mlx_start(t_data *data)
{
	t_mlx			mlx;

	data->mlx = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "wolf3d");
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, W_WIDTH, W_HEIGHT);
	mlx_hook(mlx.win_ptr, 2, 3, key_hook, data);
	mlx_expose_hook(mlx.win_ptr, wolf_loop, data);
	mlx_loop_hook(mlx.mlx_ptr, wolf_loop, data);
	mlx_loop(mlx.mlx_ptr);
}
