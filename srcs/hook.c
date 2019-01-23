/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:25:38 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/23 23:04:39 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void change_scale(t_screen *screen, int flag)
{
	if (flag == 1)
		screen->scale += 30;
	else
		screen->scale -= 30;
	//

}

int		key_press(int key, t_screen *screen)
{
	key == 53 ? exit(0) : 0;
	// red button click need exit too
	key == 24 ? change_scale(screen, -1) : 0;
	key == 27 ? change_scale(screen, 1) : 0;
	//mlx_destroy_image(
	julia(10, 20 + check++, screen);
	return (0);
}
