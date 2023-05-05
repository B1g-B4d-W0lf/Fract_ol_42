/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:26:56 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/06 01:15:31 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	trgb_creator( float n)
{
	t_colors	ints;
	
	ints.t = 0;
 	n = n / NMAX;
 	ints.r = 9.0 * (1 - n) * pow(n, 3) * 255.0;
 	ints.g = 15.0 * pow((1 - n), 2) * pow(n, 2) * 255.0;
 	ints.b = 8.5 * pow((1 - n), 3) * n * 255.0;
	return (((int)ints.r << 16) | ((int)ints.g << 8) | ((int)ints.b));
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

float	calculing_julia(t_complex c, float n)
{
	t_complex	z;
	t_complex	tmp;
	
	n = 0;
	z.re = -0.70176;
	tmp.re = 0;
	z.im = - 0.3842;
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

void	draw_julia(t_data img)
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
			c.re = ((x * 4) / WIDTH) - 2;
			c.im = ((y * 4) / HEIGHT) - 2;
			n = calculing_julia(c, n);
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

int	main(void)
{
	t_vars	vars;
	t_data	img;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fract_Ol");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_julia(img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, closed, &vars);
	mlx_hook(vars.win, 17, 1L<<17, cross, &vars);
	mlx_loop(vars.mlx);
}
