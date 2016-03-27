#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "libf.h"

# define W_WIDTH			1600
# define W_HEIGHT			1200

# define ESC				53
# define LARROW				123
# define RARROW				124
# define DARROW				125
# define UARROW				126
# define D_KEY				2
# define A_KEY				0
# define W_KEY				13
# define S_KEY				1
# define PLUS				69
# define MINUS				78
# define RETURN				36

typedef struct				s_vec2d
{
	double					x;
	double					y;
}							t_vec2d;

typedef struct				s_eye
{
	t_vec2d					pos;
	t_vec2d					dir;
	t_vec2d					plane;
}							t_eye;

typedef struct				s_data
{
	t_eye					eye;
	t_mlx					*mlx;	
}							t_data;