#include "fractol.h"

void	sierpinski(t_screen *screen)
{
	//scale trouble when use "-" twice
	int i = 0;
	int j = 0;
	int d;
	double dim;
	dim = 1 / screen->scale;
	while (i < screen->iteration && dim <= HEIGHT && dim <= WIDTH)
	{
		dim *= 3.0;
		i++;
	}
	i = 0;
	while (i < HEIGHT && i <= dim)
	{
		j = 0;
		while (j < WIDTH && j <= dim)
		{
			d = dim / 3.0;
			while (d)
			{
				if ((i % (d * 3) / d == 1) && (j % ((d * 3)) /d == 1))
					set_pixel(screen, i, j, d * 0x120);
				d /= 3.0;
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
