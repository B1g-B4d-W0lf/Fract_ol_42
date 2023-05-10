/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:33:55 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/11 00:02:24 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	make_mandel(t_vars *vars)
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
	draw_mandel(img, *vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}

void	make_mandel_win(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(0);
	}
	make_mandel(vars);
	management(vars);
	mlx_loop(vars->mlx);
}

float	calculing_mandel(t_complex c, float n)
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
			break ;
	}
	return (n);
}

void	draw_mandel(t_data img, t_vars vars)
{
	t_complex	c;
	float		x;
	float		y;
	float		n;

	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		while (y <= HEIGHT)
		{
			c.re = ((x * vars.resize) / WIDTH) - vars.re;
			c.im = ((y * vars.imsize) / HEIGHT) - vars.im;
			n = calculing_mandel(c, n);
			if (n != NMAX)
			{
				my_mlx_pixel_put(&img, x, y, trgb_creator(n));
			}
			y++;
		}
		y = 0;
		x++;
	}
}
