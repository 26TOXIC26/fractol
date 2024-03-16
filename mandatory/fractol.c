/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/16 07:32:10 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	t_comp pixel;
	t_comp scile;
	pixel.real = 400;
	pixel.imaginer = 400;
	scile.real = (pixel.real/400) * 4 - 2;
	scile.imaginer = ((pixel.imaginer / 400) * 4 - 2) * -1;

	printf("x--->%f\ny-->%f\n", scile.real, scile.imaginer);
		
}