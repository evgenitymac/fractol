#include "fractol.h"
	
void	burning_ship(t_screen *screen)
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
			if (iteration == screen->iteration)
				set_pixel(screen, col, row, iteration * 0x120);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
