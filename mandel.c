/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:33:55 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/06 00:42:06 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
			break;
	}
	return (n);
}

void	draw_mandel(t_data img)
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
