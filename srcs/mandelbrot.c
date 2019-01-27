
#include "fractol.h"

void	mandelbrot(t_screen *screen)
{
	int row = 0;
	int col = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			double c_re = (col - WIDTH / 2.0) * 4.0 / WIDTH;
			double c_im = (row - HEIGHT / 2.0) * 4.0 / WIDTH;
			c_re /= screen->scale;
			c_im /= screen->scale;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < screen->iteration)
			{
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im + screen->offset_y;
				x = x_new + screen->offset_x;
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
