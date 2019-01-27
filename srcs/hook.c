/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:25:38 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/24 20:23:23 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void change_scale(t_screen *screen, int flag)
{
	
	if (flag == 1)
		screen->scale += 0.4;
	else
		screen->scale -= 0.4;
}

int		key_press(int key, t_screen *screen)
{
	clear_image(&screen->img);
	key == 53 ? exit(0) : 0;
	key == 13 ? screen->offset_y += 0.1 : 0;
	key == 2 ? screen->offset_x += 0.1 : 0;
	key == 1 ? screen->offset_y -= 0.1 : 0;
	key == 0 ? screen->offset_x -= 0.1 : 0;
	// red button click need exit too
	key == 15 ? init(screen, 1) : 0;
	key == 24 ? change_scale(screen, -1) : 0;
	key == 27 ? change_scale(screen, 1) : 0;
	key == 34 ? screen->iteration += 1 : 0;
	if (screen->id == 0)
		julia(screen);
	else if (screen->id == 1)
		mandelbrot(screen);
	else if (screen->id == 2)
		tricorn(screen);
	else if (screen->id == 3)
		burning_ship(screen);
	return (0);
}
