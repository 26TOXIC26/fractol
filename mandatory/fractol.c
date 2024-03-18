/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/18 07:05:14 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_all(int keycode, t_ml *param)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	return (0);
}

int	main()
{
	t_ml param;
	t_data	img;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(param.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mandelbrot(img);
	mlx_put_image_to_window(param.mlx, param.win, img.img, 0, 0);
	mlx_hook(param.win, 2, 1L<<0, close_all, &param);
	mlx_loop(param.mlx);
}
