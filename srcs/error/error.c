#include "wolf3d"

void					error_input(void)
{
	ft_putendl_fd("./wolf3d: Wrong input", 2);
	ft_putendl_fd("usage: ./wolf3d [no arguments]", 2);
	exit(0);
}