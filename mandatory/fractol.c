/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/16 02:00:32 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_comp x;
	int x_sc;
	int y_sc;
	x.real = 100;
	x.imaginer = 200;
	x_sc = (x.real/400) * 4 - 2;
	y_sc = ((x.imaginer/400) * 4 - 2) * -1;

	printf("x--->%d\ny-->%d\n", x_sc, y_sc);
		
}