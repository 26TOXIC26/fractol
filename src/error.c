/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:24:39 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/23 01:11:34 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	is_error(void)
{
	ft_putstr_fd("--->To run the program just write ", 2);
	ft_putstr_fd("'mandelbrot' or 'julia' or 'ship' in first arg\n", 2);
	ft_putstr_fd("---> In case you write julia make ", 2);
	ft_putstr_fd("sure your next arg is must be numbers\n", 2);
	ft_putstr_fd("				[EXMPLES]\n", 2);
	ft_putstr_fd("        ./fractol mandelbrot\n", 2);
	ft_putstr_fd("        ./fractol julia 0.15 0.78\n", 2);
	ft_putstr_fd("        ./fractol ship\n", 2);
	exit(0);
}
