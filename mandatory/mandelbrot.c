/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 04:13:03 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/18 07:14:04 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_do(double cr, double  ci)
{
	double tmp;
	t_comp z;
	z.r = 0;
	z.i = 0;
	int i = 0;

	while (i < 1000)
	{
		if ((z.r * z.r + z.i * z.i) > 4.0)
			break;
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i;
		z.r = tmp;
		z.r += cr;
		z.i += ci;
		i++;
	}
	return (i);
}

void mandelbrot(t_data img)
{
    t_comp pixel;
	t_comp scile;

    pixel.i = 0;
	pixel.r = 0;

    while (pixel.i < HEIGHT)
	{
		scile.i = ((pixel.i / HEIGHT) * 4 - 2) * -1;
		while (pixel.r < WIDTH)
		{
			scile.r = (pixel.r/WIDTH) * 4 - 2;
            if (mandelbrot_do(scile.r, scile.i) == 1000)
                my_mlx_pixel_put(&img, pixel.r, pixel.i, 0x00000000);
			else
				my_mlx_pixel_put(&img, pixel.r, pixel.i, (mandelbrot_do(scile.r, scile.i) * 300)<<8);
			pixel.r++;
		}
		pixel.i++;
		pixel.r = 0;
	}
}