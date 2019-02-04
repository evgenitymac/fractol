/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsleyfern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:59:19 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 00:22:56 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	barnsley(t_screen *screen)
{
	double x0 = 0, y0 = 0, x1, y1;
	int i = 0;
	while (i <= HEIGHT * WIDTH * screen->iteration)
	{
		int dice = rand() % 100;
		if (dice == 0)
		{
			x1 = 0;
			y1 = 0.16 * y0;
		}
		else if (dice >= 1 && dice <= 7)
		{
			x1 = -0.15 * x0 + 0.28 * y0;
			y1 = 0.26 * x0 + 0.24 * y0 + 0.44;
		}
		else if (dice >= 8 && dice <= 15)
		{
			x1 = 0.2 * x0 - 0.26 * y0;
			y1 = 0.23 * x0 - 0.22 * y0 + 1.6;	
		}
		else
		{
			x1 = 0.85 * x0 + 0.04 * y0;
			y1 = -0.04 * x0 + 0.85 * y0 + 1.6;
		}
		set_pixel(screen, 30*x1 + (double)WIDTH / 2.0, 30 * y1 + HEIGHT/3, i * 0xDDF9DC);
		x0 /= screen->scale;
		y0 /= screen->scale;
		x0 = x1 + screen->offset_x;
		y0 = y1 + screen->offset_y;
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
