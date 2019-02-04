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
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < screen->iteration)
			{
				double x_new = x*x - y*y + zx;
				y = 2*x*y + zy;// + screen->offset_y;
				x = x_new;// + screen->offset_x;
				iteration++;
			}
			if (iteration < screen->iteration)
				set_pixel(screen, col, screen->row, set_color(screen, iteration));
			col++;
		}
		screen->row++;
	}
	return (tab);
}

void	mandelbrot(t_screen *screen)
{
	pthread_t thread[8];
	t_screen tab[8];
	
	clear_image(&screen->img);
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

