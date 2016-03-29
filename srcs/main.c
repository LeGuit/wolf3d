#include "wold3d.h"

static void				init_texture(t_data *data)
{
	data->texture[0] = NORTH;
	data->texture[1] = SOUTH;
	data->texture[2] = EST;
	data->texture[3] = WEST;
	// data->texture[4] = FLOOR;
	// data->texture[5] = SKY;
}

int						main(int ac, char **av)
{
	t_data				data;
	if (ac != 1)
		error_input();
	init_texture(&data);
	mlx_start(&data);
	return (0);
}