/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/10 23:44:01 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int x = 55;
    int y = 55;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 85)
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
        x++;
        if (x == 85)
        {
            while (y < 85)
            {
                my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
                y++;
                if (y == 85)
                {
                    while (x > 55)
                    {
                        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
                        x--;
                        if (x == 55)
                        {
                            while (y > 55)
                            {
                                my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
                                y--;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
        }
        
    }
    
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}