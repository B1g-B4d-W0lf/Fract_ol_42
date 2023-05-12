/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:27:12 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 21:50:46 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>

# define NMAX 200.
# define HEIGHT 1080
# define WIDTH 1080
# define MANDEL 1
# define JULIA 2

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} ;

// structures
typedef struct s_complex
{
	float	re;
	float	im;
}			t_complex;

typedef struct s_colors
{
	float	t;
	float	r;
	float	g;
	float	b;
}			t_colors;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	float		resize;
	float		imsize;
	float		re;
	float		im;
	int			fract;
	t_complex	c;
	int			color;
}				t_vars;

typedef struct s_sier
{
	t_complex	z;
	t_complex	t;
	t_complex	h;
	t_complex	zt;
	t_complex	th;
	t_complex 	hz;
	float		x_start;
	float		y_start;
	float		x_end;
	float		y_end;
	float		x;
	float		y;
	float		fx;
	float		fy;
	float		steps;
	float		x_i;
	float		y_i;
}			t_sier;

//colors
int		trgb_creator(float n, t_vars vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	rainbow(int keycode, t_vars *vars);

//mandel
void	draw_mandel(t_data img, t_vars vars);
float	calculing_mandel(t_complex c, float n);
void	make_mandel(t_vars *vars);
void	make_mandel_win(t_vars *vars);

//julia
void	draw_julia(t_data *img, t_vars vars);
float	calculing_julia(t_complex c, float n, t_vars vars);
void	make_julia_win(t_vars *vars);
void	make_julia(t_vars *vars);

//mlx
int		mousezoom(int scroll, int x, int y, t_vars *vars);
void	management(t_vars *vars);
int		zooming(t_vars *vars);
int		closed(int keycode, t_vars *vars);
int		cross(t_vars *vars);
void	ft_destroy(t_vars *vars);

void	make_sierpinski_win(t_vars *vars);

#endif