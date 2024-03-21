/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/21 07:25:00 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_ml *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void get_mlx(t_ml *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Hello world!");
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length,
									&fractol->endian);
}
void data_insialize(t_ml *fractol)
{
	fractol->zoom = 1;
	fractol->itr = 40;
	fractol->shift = 3;
}
int	main(int argc, char **argv)
{
	t_ml fractol;
	
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)))
	{
		get_mlx(&fractol);
		data_insialize(&fractol);
		mandelbrot(fractol);
		hook(&fractol);
		mlx_loop(fractol.mlx);
	}
	else if (argc == 4 && (!ft_strncmp(argv[1], "julia", 5)))
	{
		get_mlx(&fractol);
		data_insialize(&fractol);
		fractol.julia_x = atodbl(argv[2]);
		fractol.julia_y = atodbl(argv[3]);
		julia(fractol);
		hook(&fractol);
		mlx_loop(fractol.mlx);
	}
	
}
