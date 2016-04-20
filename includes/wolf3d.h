/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:47:48 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/29 16:47:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "libft.h"

# define W_WIDTH		1600
# define W_HEIGHT		1200
# define SPEED			0.2
# define DENSITY		15

# define ESC			53
# define LEFT_A			123
# define RIGHT_A		124
# define DOWN_A			125
# define UP_A			126
# define D_KEY			2
# define A_KEY			0
# define W_KEY			13
# define S_KEY			1

# define A_SET			(1u << 0)
# define W_SET			(1u << 1)
# define D_SET			(1u << 2)
# define S_SET			(1u << 3)
# define RIGHT_SET		(1u << 4)
# define LEFT_SET		(1u << 5)
/*
** WALL COLORS
*/
# define NORTH			0xFF0000
# define SOUTH			0x0000FF
# define EST			0x00FF00
# define WEST			0xFFFF00
# define FLOOR			0x88421D
# define SKY			0x99FFFF

typedef struct			s_vec2d
{
	double				x;
	double				y;
}						t_vec2d;

typedef struct			s_vec2i
{
	int					x;
	int					y;
}						t_vec2i;

typedef struct			s_eye
{
	t_vec2d				pos;
	t_vec2d				dir;
	t_vec2d				plane;
}						t_eye;

typedef struct			s_ray
{
	double				camera;
	t_vec2d				raypos;
	t_vec2d				raydir;

}						t_ray;

typedef struct			s_calcul
{
	t_vec2i				map;
	t_vec2i				step;
	t_vec2d				side;
	int					hitside;
	int					hit;
	double				nwdist;
	int					lheight;
	int					dstart;
	int					dend;
	t_vec2d				delta;

}						t_calcul;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_image				screen;
}						t_mlx;

typedef struct			s_data
{
	int					**map;
	t_eye				eye;
	t_mlx				*mlx;
	int					nrow;
	int					ncol;
	int					flag;
	int					minimapflag;
}						t_data;

void					get_map(char *av, t_data *data);
void					rand_map(char *av, t_data *d);
void					malloc_map(t_data *d, int ncol, int nrow);
void					print_map(t_data *d);
/*
** HOOKS
*/
// int						hover_hook(int x, int y, t_data *data);
int						key_hook(int key, t_data *data);
// int						mouse_hook(int button, int x, int y, void *data);
int						rot_hook(int key, t_data *data);
int						move_hook(int key, t_data *data);
void					minimap(t_data *d);
/*
** MLX
*/
void					mlx_start(t_data *data);
void					draw(t_data *data);
/*
** CALCUL
*/
void					get_ray(int x, t_ray *r, t_data *d);
void					get_calcul(t_calcul *c, t_ray *r);
void					get_steps(t_calcul *c, t_ray *r);
void					dda(t_calcul *c, t_data *d);
void					get_normedist(t_calcul *c, t_ray *r);
void					get_draw(t_calcul *c);
/*
** ERROR
*/
void					error_input(void);
void					error_file(int error);
void					error_open(void);
void					error_malloc(void);
#endif
