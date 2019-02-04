/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:45:59 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/04 21:39:29 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	*render(void *tab)
{
	t_screen *screen;

	screen = (t_screen *)tab;
	while (screen->row < screen->row_max)
	{
		int	col = 0;
		while (col < WIDTH)
		{
			double zx = (col - WIDTH / 2.0) * 4.0 / WIDTH;
			double zy = (screen->row - HEIGHT / 2.0) * 4.0 / WIDTH;
			zx /= screen->scale;
			zy /= screen->scale;
			zy += screen->offset_y;
			zx -= screen->offset_x;
			int iteration = 0;
			while (zx*zx + zy*zy <= 4 && iteration < screen->iteration)
			{
				double x_temp = zy*zy - zx*zx;
				zy = 2 * zy * zx + screen->mouse_y * 0.001; // + screen->offset_y;
				zx = x_temp + screen->mouse_x * 0.001; //+ screen->offset_x;
				iteration++;
			}
			if (iteration < screen->iteration)
				set_pixel(screen, col, screen->row, iteration * 0x120);
			col++;
		}
		screen->row++;
	}
	return (tab);
}

void	julia(t_screen *screen)
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
