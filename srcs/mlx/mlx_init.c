#include "wolf3d.h"
#include "mlx.h"

static void			init_views(t_data *data, t_mlx *mlx)
{
	data->v_world.xmin = -(data->ncol) / 1.3f;
	data->v_world.xmax = (data->ncol) / 1.3f;
	data->v_world.ymin = -(data->nrow) / 1.3f;
	data->v_world.ymax = (data->nrow) / 1.3f;
	mlx->v_screen.xmin = 0.f;
	mlx->v_screen.xmax = (float)mlx->screen.width;
	mlx->v_screen.ymin = 0.f;
	mlx->v_screen.ymax = (float)mlx->screen.height;
}

int					wolf_loop(t_data *data)
{
	ft_bzero(data->mlx->screen.data, data->mlx->screen.width
		* data->mlx->screen.height * 4);
	draw(data, data->mlx);
	return (0);
}

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	data->mlx = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, data->name);
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, W_WIDTH, W_HEIGHT);
	init_views(data);
	mlx_key_hook(mlx.win_ptr, key_hook, data);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, data);
	mlx_expose_hook(mlx.win_ptr, wolf_loop, data);
	mlx_hook(mlx.win_ptr, MOTION_NOTIFY, MOTION_MASK, hover_hook, data);
	mlx_loop_hook(mlx.mlx_ptr, wolf_loop, data);
	mlx_loop(mlx.mlx_ptr);
}
