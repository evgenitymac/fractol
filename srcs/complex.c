/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:38:42 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/24 22:45:52 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		complex_add(t_complex a, t_complex b)
{
	t_complex	c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);	
}

t_complex		complex_sqrt(t_complex a)
{
	t_complex	b;
	b.x = a.x * a.x - a.y * a.y;
	b.y = 2 * a.x * a.y;
	return (b);
}

double		complex_mod(t_complex	a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

t_complex	map_point(t_screen *screen, int x, int y)
{
	t_complex	a;

	a.x = 100 - (WIDTH / 2);
	a.y = 100 - (HEIGHT / 2);
	a.x /= screen->scale;
	a.y /= screen->scale;
//	a.x += center_x;
//	a.y += center_y;
	
	return (a);	
}
