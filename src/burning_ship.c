/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 04:08:37 by pc                #+#    #+#             */
/*   Updated: 2024/03/22 05:35:51 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int buring_ship_do(double cr, double ci, t_ml fractol)
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
        z.r = fabs(z.r);
        z.i = fabs(z.i);
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i + ci;
		z.r = tmp + cr;
		i++;
	}
	return (0);
}
void burning_ship(t_ml fractol)
{
    t_ml	pixel;
	t_ml	scile;

	pixel.i = 0;
	pixel.r = 0;
	while (pixel.i < HEIGHT)
	{
		scile.i = ((((pixel.i / HEIGHT) * 4 - 2) * -1) * fractol.zoom
			+ fractol.plus_y + fractol.mainis_y) * -1;
		while (pixel.r < WIDTH)
		{
			scile.r = ((pixel.r / WIDTH) * 4 - 2) * fractol.zoom
				+ fractol.plus_x + fractol.mainis_x;
			if (buring_ship_do(scile.r, scile.i, fractol) == 0)
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i, 0x00000000);
			else
				my_mlx_pixel_put(&fractol, pixel.r, pixel.i,
					(buring_ship_do(scile.r, scile.i, fractol)
						* 290) << fractol.shift);
			pixel.r++;
		}
		pixel.i++;
		pixel.r = 0;
    }
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
}
