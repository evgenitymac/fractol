/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:24:49 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 23:29:05 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		iteration(t_helper *cache)
{
	cache->x_temp = cache->x0 *
		cache->x0 - cache->y0 * cache->y0 + cache->x1;
	cache->y0 = -2 * cache->x0 * cache->y0 + cache->y1;
	cache->x0 = cache->x_temp;
	cache->i++;
}

void			*tricorn(void *tab)
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
				iteration(&cache);
			if (cache.i != screen->iteration)
				set_pixel(screen, col, screen->row, set_color(screen, cache.i));
			col++;
		}
		screen->row++;
	}
	return (tab);
}
