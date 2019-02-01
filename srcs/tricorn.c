#include "fractol.h"

void	tricorn(t_screen *screen)
{
	int row = 0;
	int col = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			double zx = (col - WIDTH / 2.0) * 4.0 / WIDTH + screen->offset_x;
			double zy = (row - HEIGHT / 2.0) * 4.0 / WIDTH + screen->offset_y;
			zx /= screen->scale;
			zy /= screen->scale;
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
			if (iteration == screen->iteration)
				set_pixel(screen, col, row, iteration * 0xFFFFFF);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
