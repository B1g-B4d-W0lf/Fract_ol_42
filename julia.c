/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:34:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/06 21:50:46 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	calculing_julia(t_complex c, float n)
{
	t_complex	z;
	t_complex	tmp;

	n = 0;
	z = c;
	c.re = -0.162;
	c.im = 1.04;
	tmp.re = 0;
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
			c.re = ((x * RESIZE) / WIDTH) - RE;
			c.im = ((y * IMSIZE) / HEIGHT) - IM;
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
