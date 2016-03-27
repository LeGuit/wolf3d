#include "wolf3d.h"
#include "math.h"

static int				rot_lf(t_data *data)
{
		data->eye.x += ;
		data->eye.y += ;
	return (0);
}

static int				rot_rg(t_data *data)
{
		data->eye.x -= ;
		data->eye.y -= ;
	return (0);
}

/*
** BONUS -> can be used by mouse maybe
*/
/*static int				rot_up(t_data *data)
{
		data->eye.x += ;
		data->eye.y += ;
	return (0);
}

static int					rot_dw(t_data *data)
{
		data->eye.x += ;
		data->eye.y += ;
	return (0);
}
*/

int						rot_hook(int key, t_data *data)
{
	if (key == LEFT_A)
		rot_lf(data);
	else if (key == RIGHT_A)
		rot_rg(data);
	// else if (key == UP_A)
	// 	rot_up(data);
	// else if (key == DOWN_A)
	// 	rot_dw(data);
	return (0);
}
