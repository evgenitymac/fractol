/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:45:59 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 21:54:59 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	iteration(t_helper *cache, t_screen *screen)
{
	cache->x_temp = cache->y0 * cache->y0 - cache->x0 * cache->x0;
	cache->y0 = 2 * cache->y0 * cache->x0 + screen->mouse_y * 0.001;
	cache->x0 = cache->x_temp + screen->mouse_x * 0.001;
	cache->i++;
}

void			*julia(void *tab)
{
	t_screen	*screen;
	t_helper	cache;
	int			col;

	screen = (t_screen *)tab;
	while (screen->row < screen->row_max)
	{
		col = 0;
		while (col < WIDTH)
		{
			init_helper(&cache, screen, col);
			while (cache.x0 * cache.x0 - cache.y1 * cache.y1
					<= 4 && cache.i < screen->iteration)
				iteration(&cache, screen);
			if (cache.i != screen->iteration)
				set_pixel(screen, col, screen->row, set_color(screen, cache.i));
			col++;
		}
		screen->row++;
	}
	return (tab);
}
