#include "wolf3d.h"

static int			move_fw(t_data *data)
{
	if (//nowall)
	{
		data->eye.x += ;
		data->eye.y += ;
	}
	return (0);
}

static int			move_bw(t_data *data)
{
	if (//nowall)
	{
		data->eye.x -= ;
		data->eye.y -= ;
	}
	return (0);
}

/*
** BONUS
*/
/*static int			straf_rg(t_data *data)
{
	if (//nowall)
	{
		data->eye.x += ;
		data->eye.y += ;
	}
	return (0);
}

static int			straf_lf(t_data *data)
{
	if (//nowall)
	{
		data->eye.x += ;
		data->eye.y += ;
	}
	return (0);
}
*/

int					move_hook(int key, t_data *data)
{
	if (key == W_KEY)
		move_fw(data);
	else if (key == S_KEY)
		move_bw(data);
	else if (key == D_KEY)
		straf_rg(data);
	else if (key == A_KEY)
		straf_lf(data);
	return (0);
}
