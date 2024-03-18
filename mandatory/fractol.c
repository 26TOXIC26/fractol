/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/18 02:24:24 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int man(double cr, double  ci)
{
	double tmp;
	t_comp z;
	z.r = 0;
	z.i = 0;
	int i = 0;

	while (i < 40)
	{
		if ((z.r * z.r + z.i * z.i) > 4.0 && (z.r * z.r + z.i * z.i) < 6.0)
			return (0);
		else if ((z.r * z.r + z.i * z.i) >= 6.0)
			return (2);
		tmp = (z.r * z.r) - (z.i * z.i);
		z.i = 2 * z.r * z.i;
		z.r = tmp;
		z.r += cr;
		z.i += ci;
		i++;
	}
	return (1);
}
int	main()
{
	t_comp pixel;
	t_comp scile;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	

	pixel.i = 0;
	pixel.r = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (pixel.i < 400)
	{
		scile.i = ((pixel.i / 400) * 4 - 2) * -1;
		while (pixel.r < 400)
		{
			scile.r = (pixel.r/400) * 4 - 2;	
			if (man(scile.r, scile.i) == 0)
				my_mlx_pixel_put(&img, pixel.r, pixel.i, 0x00FF0000);
			else if (man(scile.r, scile.i) == 1)
				my_mlx_pixel_put(&img, pixel.r, pixel.i, 0x000000FF);
			else
				my_mlx_pixel_put(&img, pixel.r, pixel.i, 0x00FFFF00);
			pixel.r++;
		}
		pixel.i++;
		pixel.r = 0;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);	
}