/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:59:03 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 00:13:29 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_screen *screen)
{
	screen->img.image = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->img.ptr = mlx_get_data_addr(screen->img.image, &screen->img.bpp,
			&screen->img.size_line, &screen->img.endian);
	screen->img.bpp /= 8;
}

void	set_pixel(t_screen *screen, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	((int*)(screen->img.ptr))[y * WIDTH + x] = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, WIDTH * HEIGHT * img->bpp);
}

int		set_color(t_screen *screen, int iteration)
{
	int palitra;
	
	palitra = screen->iteration - iteration + 1;
	if (iteration % 2 == 0)
		palitra *= 0x5e1914;
	else
		palitra *= 0x006400;
	return (palitra);
}
