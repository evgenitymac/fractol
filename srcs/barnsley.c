/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsleyfern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:59:19 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 21:29:24 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		barnsley_helper(t_helper *cache)
{
	cache->x0 = 0;
	cache->y0 = 0;
	cache->x1 = 0;
	cache->y1 = 0;
	cache->i = 0;
}

static	void	iteration(t_helper *cache, t_screen *screen)
{
	set_pixel(screen, 30 * cache->x1 + (double)WIDTH /
			2.0, 30 * cache->y1 + HEIGHT / 3, set_color(screen, cache->i));
	cache->x0 /= screen->scale;
	cache->y0 /= screen->scale;
	cache->x0 = cache->x1 + screen->offset_x;
	cache->y0 = cache->y1 + screen->offset_y;
	cache->i++;
}

static	void	way_out(t_helper *cache, int dice)
{
	if (dice == 0)
	{
		cache->x1 = 0;
		cache->y1 = 0.16 * cache->y0;
	}
	else if (dice >= 1 && dice <= 7)
	{
		cache->x1 = -0.15 * cache->x0 + 0.28 * cache->y0;
		cache->y1 = 0.26 * cache->x0 + 0.24 * cache->y0 + 0.44;
	}
	else if (dice >= 8 && dice <= 15)
	{
		cache->x1 = 0.2 * cache->x0 - 0.26 * cache->y0;
		cache->y1 = 0.23 * cache->x0 - 0.22 * cache->y0 + 1.6;
	}
	else
	{
		cache->x1 = 0.85 * cache->x0 + 0.04 * cache->y0;
		cache->y1 = -0.04 * cache->x0 + 0.85 * cache->y0 + 1.6;
	}
}

void			barnsley(t_screen *screen)
{
	t_helper	cache;
	int			dice;

	barnsley_helper(&cache);
	while (cache.i <= HEIGHT * WIDTH * screen->iteration)
	{
		dice = rand() % 100;
		way_out(&cache, dice);
		iteration(&cache, screen);
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img.image, 0, 0);
}
