#include "fractol.h"

void	sierpinski(t_screen *screen)
{
	int iteration = 0;
	int y = 0;
	int x = 0;
	while (iteration < screen->iteration)
	{
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
			    if (x % 3 == 1 && y % 3 == 1)
					set_pixel(screen, x, y, 0xFFFFFF);
				x++;
			}
			y++;
		}
		iteration++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
