/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 04:13:03 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/21 23:29:42 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_do(double cr, double ci, t_ml fractol)
{
	double	tmp;
	int		i;
	t_ml	z;

	z.r = 0;
	z.i = 0;
	tmp = 0.0;
	i = 0;
	while (i < fractol.itr)
	{
		if ((z.r * z.r + z.i * z.i) > 4.0)
			return (i);
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i;
		z.r = tmp;
		z.r += cr;
		z.i += ci;
		i++;
	}
	return (0);
}

void	mandelbrot(t_ml fractol)
{
	t_ml	pixel;
	t_ml	scile;

	pixel.i = 0;
	pixel.r = 0;
	while (pixel.i < HEIGHT)
	{
		scile.i = (((pixel.i / HEIGHT) * 4 - 2) * -1) * fractol.zoom
			+ fractol.plus_y + fractol.mainis_y;
		while (pixel.r < WIDTH)
		{
			scile.r = ((pixel.r / WIDTH) * 4 - 2) * fractol.zoom
				+ fractol.plus_x + fractol.mainis_x;
			if (mandelbrot_do(scile.r, scile.i, fractol) == 0)
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i, 0x00000000);
			else
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i,
					(mandelbrot_do(scile.r, scile.i, fractol)
						* 290) << fractol.shift);
			pixel.r++;
		}
		pixel.i++;
		pixel.r = 0;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
}
