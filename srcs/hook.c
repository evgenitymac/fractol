/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:25:38 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 00:12:23 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	show_fractal(t_screen *screen)
{
	clear_image(&screen->img);
	if (screen->id == 0)
		julia(screen);
	else if (screen->id == 1)
		mandelbrot(screen);
	else if (screen->id == 2)
		tricorn(screen);
	else if (screen->id == 3)
		burning_ship(screen);
	else if (screen->id == 4)
		sierpinski(screen);
	else if (screen->id == 5)
		barnsley(screen);
	else if (screen->id == 6)
		sunflower(screen);
}

int		close_this(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		key_press(int key, t_screen *screen)
{
	key == 53 ? exit(0) : 0;
	key == 126 ? screen->offset_y += 0.04 / screen->scale : 0;
	key == 124 ? screen->offset_x += 0.04 / screen->scale : 0;
	key == 125 ? screen->offset_y -= 0.04 / screen->scale : 0;
	key == 123 ? screen->offset_x -= 0.04 / screen->scale : 0;
	key == 15 ? init(screen, 1) : 0;
	key == 24 ? screen->scale += 0.4 : 0;
	key == 27 ? screen->scale -= 0.4 : 0;
	key == 34 ? screen->iteration += 1 : 0;
	key == 49 ? screen->is_fixed += 1 : 0;
	show_fractal(screen);
	return (0);
}

int		mouse_move(int x, int y, t_screen *screen)
{
	if (x >= 0 && x<= WIDTH && y>= 0 && y <= HEIGHT)
	{
		if (screen->is_fixed % 2 == 1 && screen->id == 0)
		{
			screen->mouse_x = x;
			screen->mouse_y = y;
			show_fractal(screen);
		}
	}
	return (0);
}
int		mouse_press(int button, int x, int y, t_screen *screen)
{
	if (screen->is_fixed % 2 == 0)
	{	
		if (button == 4)
		{
			screen->scale *= 1.1;
			screen->offset_x -= (x - WIDTH / 2) * 0.0009 / screen->scale;
			screen->offset_y += (y - HEIGHT / 2) * 0.0009 / screen->scale;
		}
		if (button == 5)
		{
			screen->scale *= 0.9;
			//screen->offset_x -= (x - WIDTH / 2) * 0.0009 / screen->scale;
			//screen->offset_y += (y - HEIGHT / 2) * 0.0009 / screen->scale;
		}
	}
	show_fractal(screen);
	return (0);
}
