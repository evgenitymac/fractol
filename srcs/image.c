/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:59:03 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/04 21:02:08 by maheiden         ###   ########.fr       */
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
