#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "libf.h"

# define W_WIDTH		1600
# define W_HEIGHT		1200

# define ESC			53
# define LEFT_A			123
# define RIGHT_A		124
# define DOWN_A			125
# define UP_A			126
# define D_KEY			2
# define A_KEY			0
# define W_KEY			13
# define S_KEY			1
# define PLUS			69
# define MINUS			78
# define RETURN			36

/*
** WALL COLORS
*/
# define NORTH
# define SOUTH
# define EST
# define WEST
# define FLOOR
# define SKY

typedef struct			s_vec2d
{
	double				x;
	double				y;
}						t_vec2d;

typedef struct			s_eye
{
	t_vec2d				pos;
	t_vec2d				dir;
	t_vec2d				plane;
}						t_eye;

typedef struct			s_data
{
	t_eye				eye;
	t_mlx				*mlx;
	int					texture[6]; //N->S->E->O
}						t_data;

/*
** HOOKS
*/
int						hover_hook(int x, int y, t_data *data);
int						key_hook(int key, t_data *data);
int						mouse_hook(int button, int x, int y, void *data);
int						rot_hook(int key, t_data *data);
int						move_hook(int key, t_data *data);
/*
** MLX
*/
void					mlx_start(t_data *data);
/*
** ERROR
*/
void					error_input(void)

