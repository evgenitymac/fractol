/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:45:59 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/24 22:45:58 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_screen *screen)
{
	int row = 0;
	int col = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			double zx = (col - WIDTH / 2.0) * 4.0 / WIDTH;
			double zy = (row - HEIGHT / 2.0) * 4.0 / WIDTH;
			zx /= screen->scale;
			zy /= screen->scale;
			int iteration = 0;
			while (zx*zx + zy*zy <= 4 && iteration < screen->iteration)
			{
				double x_temp = zx*zx - zy*zy;
				zy =2 * zx * zy + screen->offset_y;
				zx = x_temp + screen->offset_x;
				iteration++;
			}
			if (iteration < screen->iteration)
				set_pixel(screen, col, row, iteration * 0x120);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
