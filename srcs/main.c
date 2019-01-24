/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:24:15 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/24 22:45:53 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	init(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "fractol");
	screen->scale = 200;
	init_image(screen);
}
void	display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}


int		main(int argc, char **argv)
{
	t_screen  *screen;

	screen = (t_screen *)ft_memalloc(sizeof(t_screen));
	init(screen);
	display_error(argc != 2, "arguments error");
	if (ft_strcmp(argv[1], "julia") != 0)
		return (1);
	julia(10, screen);
	mlx_hook(screen->win, 2, 0, key_press, screen);
	mlx_loop(screen->mlx);
	return (0);
}

