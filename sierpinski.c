/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:56:30 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 22:11:58 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_line(t_sier f, t_data *img, t_complex c, t_complex d)
{	
	f.x_start = c.re;
	f.y_start = c.im;
	f.x_end = d.re;
	f.y_end = d.im;
	f.fx = f.x_end - f.x_start;
	f.fy = f.y_end - f.y_start;
	f.steps = fmax(fabs(f.fx), fabs(f.fy));
	f.x_i = f.fx / f.steps;
	f.y_i = f.fy / f.steps;
	
	f.x = f.x_start;
	f.y = f.y_start;
	while (f.steps > 0)
	{
		my_mlx_pixel_put(img, round(f.x), round(f.y), 0x00660033);
		f.x += f.x_i;
		f.y += f.y_i;
		f.steps--;
	}	
}

void	calculing_sierpinski(t_data *img, t_sier f, t_complex z, t_complex t, t_complex h)
{

	draw_line(f, img, z, t);
	draw_line(f, img, t, h);
	draw_line(f, img, h, z);
}

void	draw_sierpinski(t_data *img, t_vars vars, t_sier f, t_complex z, t_complex t, t_complex h, int depth)
{
	t_complex	zt;
	t_complex	th;
	t_complex	hz;
	
	if (depth == 0)
    {
        calculing_sierpinski(img, f, z, t, h);
    }
    else
    {
		zt.re = (z.re + t.re) / 2;
		zt.im = (z.im + t.im) / 2;
    	th.re = (t.re + h.re) / 2; 
		th.im = (t.im + h.im) / 2;
    	hz.re = (h.re + z.re) / 2;
		hz.im = (h.im + z.im) / 2;
        draw_sierpinski(img, vars, f, z, th, hz, depth - 1);
        draw_sierpinski(img, vars, f, zt, t, hz, depth - 1);
        draw_sierpinski(img, vars, f, zt, th, hz, depth - 1);
    }
}

void	make_sierpinski(t_vars *vars)
{
	t_data	img;
	t_complex	z;
	t_complex	t;
	t_complex	h;
	t_sier		f;
	
	f.x = WIDTH / 2;
	f.y = HEIGHT / 2;
	z.im = f.y - (f.y / 3) * 1.8;
	z.re = f.x;
	t.im = f.y + (f.y / 6) * 1.8;
	t.re = f.x + (sqrt(f.y * f.y / 12)) * 1.8;
	h.im = f.y + (f.y / 6) * 1.8;
	h.re = f.x - (sqrt( f.y* f.y / 12)) * 1.8;
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
	draw_sierpinski(&img, *vars, f, z, t, h, 2);
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


