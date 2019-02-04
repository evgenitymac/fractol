/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunflower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 23:14:22 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/04 18:19:34 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_circle(t_screen *screen, int xc, int yc, int x, int y)
{
	set_pixel(screen, xc+x, yc+y, 0x00FF00);
	set_pixel(screen, xc-x, yc+y, 0x00FF00);
	set_pixel(screen, xc+x, yc-y, 0x00FF00);
	set_pixel(screen, xc-x, yc-y, 0x00FF00);
	set_pixel(screen, xc+y, yc+x, 0x00FF00);
	set_pixel(screen, xc-y, yc+x, 0x00FF00);
	set_pixel(screen, xc+y, yc-x, 0x00FF00);
	set_pixel(screen, xc-y, yc-x, 0x00FF00);
}

static void		circle_bres(t_screen *screen, int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	draw_circle(screen, xc, yc, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		draw_circle(screen, xc, yc, x, y);
	}
}
void	sunflower(t_screen *screen)
{

	int c = (sqrt(5) + 1)/ 2;
	int i = 0;
	int max = screen->iteration;
	int r = 0;
	int x, y = 0;
	double angle = 0;
	while (i < max)
	{
		r = pow(i, c) / max * (screen->scale + 187);	
		angle = 2 * M_PI * c * i;
		x = r * sin(angle) + WIDTH / 2;
		y = r * cos(angle) + HEIGHT / 2;
		circle_bres(screen, x, y, r);
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
