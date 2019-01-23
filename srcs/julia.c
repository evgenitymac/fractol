/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:45:59 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/23 22:34:47 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(double radius, int n, t_screen *screen)
{
	int		x;
	int		y;
	int		i;
	x = 0;
	t_complex	z0;
	t_complex	z1;
	
	mlx_clear_window(screen->mlx, screen->win);
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			z0 = map_point(screen, x, y);
			i = 1;
			while (i <= n)
			{
				z1 = complex_add(complex_sqrt(z0), screen->complex_num);
				if (complex_mod(z1) > radius) 
				{
					//mlx_pixel_put(screen->mlx, screen->win, x, y, i * 128 );
					set_pixel(screen, x, y, i * 128);
					break;
				}
				z0 = z1;
				i++;
			}
			if (i > n)
			{
				//mlx_pixel_put(screen->mlx, screen->win, x, y, 0);
				set_pixel(screen, x, y, 0);
			}
			y++;
		}
		x++;
	}
}
