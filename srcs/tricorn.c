#include "fractol.h"

static void	*render(void *tab)
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
			int iteration = 0;
			double x = zx;
			double y = zy;
			while (zx*zx + zy*zy < 4 && iteration < screen->iteration)
			{
				double xtemp = zx*zx - zy*zy + x;
				zy = -2*zx*zy + y;
				zx = xtemp;
				iteration += 1;
			}
			if (iteration != screen->iteration)
				set_pixel(screen, col, screen->row, iteration * 0x120);
			col++;
		}
		screen->row++;
	}
	return (tab);
}

void	tricorn(t_screen *screen)
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
