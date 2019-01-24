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
		screen->scale += 10;
	else
		screen->scale -= 10;
}

int		key_press(int key, t_screen *screen)
{
	clear_image(&screen->img);
	key == 53 ? exit(0) : 0;
	// red button click need exit too
	key == 24 ? change_scale(screen, -1) : 0;
	key == 27 ? change_scale(screen, 1) : 0;
	key == 1 ? ft_putendl("kek") : 0;
	julia(10, screen);
	return (0);
}
