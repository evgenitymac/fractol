/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunflower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 23:14:22 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 23:26:51 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_circle(t_screen *screen, t_circle *d)
{
	set_pixel(screen, d->xc + d->x, d->yc + d->y, set_color(screen, d->yc));
	set_pixel(screen, d->xc - d->x, d->yc + d->y, set_color(screen, d->yc));
	set_pixel(screen, d->xc + d->x, d->yc - d->y, set_color(screen, d->yc));
	set_pixel(screen, d->xc - d->x, d->yc - d->y, set_color(screen, d->yc));
	set_pixel(screen, d->xc + d->y, d->yc + d->x, set_color(screen, d->yc));
	set_pixel(screen, d->xc - d->y, d->yc + d->x, set_color(screen, d->yc));
	set_pixel(screen, d->xc + d->y, d->yc - d->x, set_color(screen, d->yc));
	set_pixel(screen, d->xc - d->y, d->yc - d->x, set_color(screen, d->yc));
}

static void		circle_bres(t_screen *screen, int xc, int yc, int r)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	draw_circle(screen, &(t_circle){xc, yc, x, y});
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
		draw_circle(screen, &(t_circle){xc, yc, x, y});
	}
}

void			sunflower(t_screen *screen)
{
	int			i;
	int			r;
	int			x;
	int			y;
	double		angle;

	i = 0;
	r = 0;
	x = 0;
	y = 0;
	angle = 0;
	while (i < screen->iteration)
	{
		r = pow(i, (int)((sqrt(5) + 1) / 2))
				/ screen->iteration * (screen->scale + 187);
		angle = 2 * M_PI * (int)((sqrt(5) + 1) / 2) * i;
		x = r * sin(angle) + WIDTH / 2;
		y = r * cos(angle) + HEIGHT * 1 / 3;
		circle_bres(screen, x, y, r);
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
