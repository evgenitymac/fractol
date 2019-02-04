/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 21:32:32 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/04 23:45:38 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
	
static	void	*render(void *tab)
{
	t_screen *screen;

	screen = (t_screen *)tab;
	while (screen->row < screen->row_max)
	{
		int col = 0;
		while (col < WIDTH)
		{
			double zx = (col - WIDTH / 2.0) * 4.0 / WIDTH;
			double zy = (screen->row - HEIGHT / 2.0) * 4.0 / WIDTH;
			zx /= screen->scale;
			zy /= screen->scale;
			zx -= screen->offset_x;
			zy += screen->offset_y;
			double x = zx, y = zy;
			int iteration = 0;
			while (zx * zx - zy * zy <= 4 && iteration < screen->iteration)
			{
				double xtemp = zx*zx - zy*zy + x;
				zy = fabs(2*zx*zy) + y; // + screen->offset_y;
				zx = fabs(xtemp);// + screen->offset_x;
				iteration++;
			}
			if (iteration != screen->iteration)
				set_pixel(screen, col, screen->row, set_color(screen, iteration));
			col++;
		}
		screen->row++;
	}
	return (tab);
}

void	burning_ship(t_screen *screen)
{
	pthread_t thread[8];
	t_screen tab[8];

	int i = -1;
	while (++i < 8)
	{
		ft_memcpy((void*)&tab[i], (void *)screen, sizeof(t_screen));
		screen->row = HEIGHT/ 8 * i;
		screen->row_max = HEIGHT / 8 * (i + 1);
		pthread_create(&thread[i], NULL, render, &tab[i]);
	}
	while (i--)
		pthread_join(thread[i], NULL);
	
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
