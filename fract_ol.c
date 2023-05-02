/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:26:56 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/02 21:55:31 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	chunksdef(int ref, t_colors ints)
{
	
	if (ref < 50000)
		return(ints.r = 255 | ints.g == 0 | ints.b == 0);
	else if (ref < 100000)
		return(ints.r = 0 | ints.g == 255 | ints.b == 100);
	else if (ref < 150000)
		return(ints.r = 0 | ints.g == 100 | ints.b == 255);
	else if (ref < 200000)
		return(ints.r = 0 | ints.g == 0 | ints.b == 255);
	else if (ref < 250000)
		return(ints.r = 0 | ints.g == 255 | ints.b == 0);
}
int	trgb_creator(t_colors ints, int axis, int ord)
{
	int	ref;

	ref = (ord * axis);
	if (ref < 50000)
		return(ints.r = 255 | ints.g == 255 | ints.b == 0);
	else if (ref < 100000)
		return(ints.r = 255 | ints.g == 255 | ints.b == 0);
	else if (ref < 150000)
		return(ints.r = 255 | ints.g == 255 | ints.b == 0);
	else if (ref < 200000)
		return(ints.r = 0 | ints.g == 255 | ints.b == 0);
	else if (ref < 250000)
		return(ints.r = 0 | ints.g == 255 | ints.b == 0);
	return (ints.t << 24 | ints.r << 16 | ints.g << 8 | ints.b);
}

void	fill_pixel(t_data img, int x, int y, t_colors ints)
{
	int	ref;
	
	while (x != 500)
	{
		ref = y;
		while (y != x)
		{
			my_mlx_pixel_put(&img, x, y, trgb_creator(ints, x, y));
			y--;
		}
		y = (ref - 1);
		x++;
	}	
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

int	main(t_colors ints)
{
	t_vars	vars;
	t_data	img;
	int		x;
	int		y;
	
	x = 3;
	y = 3;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract_Ol");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x != 500 && y != 500)
	{
		my_mlx_pixel_put(&img, x, y, trgb_creator(ints, 24, 16));
		x++;
		y++;
	}
	while (x != 3  && y != 1000)
	{
		my_mlx_pixel_put(&img, x, y, trgb_creator(ints, 24, 16));
		x--;
		y++;
	}
	fill_pixel(img, x, y, ints);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, closed, &vars);
	mlx_hook(vars.win, 17, 1L<<17, cross, &vars);
	mlx_loop(vars.mlx);
}