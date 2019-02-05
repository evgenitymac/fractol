/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:59:03 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 23:29:45 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_image(t_screen *screen)
{
	screen->img.image = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->img.ptr = mlx_get_data_addr(screen->img.image, &screen->img.bpp,
			&screen->img.size_line, &screen->img.endian);
	screen->img.bpp /= 8;
}

void			set_pixel(t_screen *screen, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((int*)(screen->img.ptr))[y * WIDTH + x] = color;
}

void			clear_image(t_img *img)
{
	ft_bzero(img->ptr, WIDTH * HEIGHT * img->bpp);
}

int				set_color(t_screen *screen, int iteration)
{
	int			palitra;

	palitra = screen->iteration - iteration + 1;
	if (iteration % 2 == 0)
		palitra *= 0x5e1914;
	else
		palitra *= 0x006400;
	return (palitra & 0xffffff);
}

void			render(t_screen *screen, void *fractal_func)
{
	pthread_t	thread[8];
	t_screen	tab[8];
	int			i;

	i = -1;
	while (++i < 8)
	{
		ft_memcpy((void*)&tab[i], (void *)screen, sizeof(t_screen));
		screen->row = HEIGHT / 8 * i;
		screen->row_max = HEIGHT / 8 * (i + 1);
		pthread_create(&thread[i], NULL, fractal_func, &tab[i]);
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
