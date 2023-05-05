/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:26:56 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/05 03:25:37 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	trgb_creator(t_colors ints)
{
	ints.r = 255;
	ints.g == 178;
	ints.b == 102;
	return (ints.t << 24 | ints.r << 16 | ints.g << 8 | ints.b);
}

int	closed(int keycode, t_vars *vars)
{
	printf("keycode >> %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return(0);
}

float	calculing(t_complex c, float n)
{
	t_complex	z;
	t_complex	tmp;
	
	n = 0;
	z.re = 0;
	tmp.re = 0;
	z.im = 0;
	tmp.im = 0;
	while (n < NMAX)
	{
		tmp.re = (z.re * z.re) - (z.im * z.im) + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z = tmp;
		n++;
		if ((z.re * z.re) + (z.im * z.im) >= 4)
			break;
	}
	return (n);
}

void	draw_fractal(int width, int height, t_data img, t_colors ints)
{
	t_complex	c;
	float	x;
	float	y;
	float	n;

	x = 0;
	y = 0;
	while (x <= width)
	{
		while (y <= height)
		{
			c.re = ((x * 4) / width) - 2;
			c.im = ((y * 4) / height) - 2;
			n = calculing(c, n);
			if (n >= NMAX)
			{
				my_mlx_pixel_put(&img, x, y, trgb_creator(ints));
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	main(t_colors ints)
{
	t_vars	vars;
	t_data	img;
	int		window_height;
	int		window_width;
	
	window_height = 1080;
	window_width = 1920;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, window_width, window_height, "Fract_Ol");
	img.img = mlx_new_image(vars.mlx, window_width, window_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_fractal(window_width, window_height, img, ints);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, closed, &vars);
	mlx_hook(vars.win, 17, 1L<<17, cross, &vars);
	mlx_loop(vars.mlx);
}
