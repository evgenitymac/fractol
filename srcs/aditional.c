/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:25:43 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 22:36:59 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_helper(t_helper *cache, t_screen *screen, int col)
{
	cache->x0 = (col - WIDTH / 2.0) * 4.0 / WIDTH;
	cache->y0 = (screen->row - HEIGHT / 2.0) * 4.0 / WIDTH;
	cache->x0 /= screen->scale;
	cache->y0 /= screen->scale;
	cache->x0 -= screen->offset_x;
	cache->y0 += screen->offset_y;
	cache->x1 = cache->x0;
	cache->y1 = cache->y0;
	cache->x_temp = 0;
	cache->i = 0;
}

void		start_sniff(t_screen *screen)
{
	mlx_hook(screen->win, 17, 0, close_this, screen);
	mlx_hook(screen->win, 6, 0, mouse_move, screen);
	mlx_mouse_hook(screen->win, mouse_press, screen);
	mlx_hook(screen->win, 2, 0, key_press, screen);
}
