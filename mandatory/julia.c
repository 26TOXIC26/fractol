/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:17:06 by pc                #+#    #+#             */
/*   Updated: 2024/03/21 07:49:12 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_do(double cr, double ci, t_ml fractol)
{
    double tmp;
	int i;
	t_ml z;
	z.r = cr;
	z.i = ci;
    cr = fractol.julia_x;
    ci = fractol.julia_y;
	tmp = 0.0;
	i = 0;

	while (i < fractol.itr)
	{
		if ((z.r * z.r + z.i * z.i) > 4.0)
			break;
		tmp = (z.r * z.r) - (z.i * z.i) + cr;
		z.i = 2 * z.r * z.i + ci;
		z.r = tmp;
		// z.r += cr;
		// z.i += ci;
		i++;
	}
	return (i);
}

void julia(t_ml fractol)
{
    t_ml pixel;
	t_ml scile;

	pixel.i = 0;
	pixel.r = 0;
	scile.r = 0;
	scile.i = 0;
	while (pixel.i < HEIGHT)
	{
		scile.i = (((pixel.i / HEIGHT) * 4 - 2) * -1) * fractol.zoom + fractol.plus_y + fractol.mainis_y;
		while (pixel.r < WIDTH)
		{
			scile.r = ((pixel.r / WIDTH) * 4 - 2) * fractol.zoom + fractol.plus_x + fractol.mainis_x;
			if (julia_do(scile.r, scile.i, fractol) == (int)fractol.itr)
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i, 0x00000000);
			else
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i, (julia_do(scile.r, scile.i, fractol) * 290) << fractol.shift);
			pixel.r++;
		}
		pixel.i++;
		pixel.r = 0;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
}
