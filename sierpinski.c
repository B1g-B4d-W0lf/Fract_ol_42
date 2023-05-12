/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:56:30 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 04:52:32 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_line(t_data *img, float x, float y)
{
	
}
void	calculing_sierpinski(t_data *img)
{
	t_complex	z;
	t_complex	t;
	t_complex	h;
	t_complex	tmp;
	float		x;
	float		y;
	
	x = WIDTH / 2;
	y = HEIGHT / 2;
	z.im = y - (y / 3) * 1.8;
	z.re = x;
	t.im = y + (y / 6) * 1.8;
	t.re = x + (sqrt(y * y / 12)) * 1.8;
	h.im = y + (y / 6) * 1.8;
	h.re = x - (sqrt( y* y / 12)) * 1.8;
	tmp = z;
	x = z.re;
	y = z.im;
	while (x <= t.re && y <= t.im)
	{
		my_mlx_pixel_put(img, x, y, 0x00660033);
		x++;
		y = y + 1.5;
	}	
	while (x >= h.re)
	{
		my_mlx_pixel_put(img, x, y, 0x00006633);
		x--;
	}
	while (x <= tmp.re && y >= tmp.im)
	{
		my_mlx_pixel_put(img, x, y, 0x00667733);
		x++;
		y = y - 1.5;
	}
}

void	draw_sierpinski(t_data *img, t_vars vars)
{
	if (vars.color == 1)
		calculing_sierpinski(img);
}

void	make_sierpinski(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		free(img.img);
		free(vars->win);
		free(vars->mlx);
		exit(0);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (!img.addr)
	{
		free(img.img);
		free(img.addr);
		free(vars->win);
		free(vars->mlx);
		exit(0);
	}
	draw_sierpinski(&img, *vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}

void	make_sierpinski_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Sierpinski");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(0);
	}
	make_sierpinski(vars);
	management(vars);
	mlx_loop(vars->mlx);
}


