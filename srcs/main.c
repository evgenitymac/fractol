/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:24:15 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/23 23:04:37 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	init(t_screen *screen)
{
	screen->win = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "fractol");
	screen->scale = 100;
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
	t_complex c;
	t_screen  screen;

	c. x = 0;
	c. y = 0;

	screen.mlx = mlx_init();
	screen.win = mlx_new_window(screen.mlx, WIDTH, HEIGHT, "fractol");
	init(&screen);

	init_image(&screen);
	display_error(argc != 2, "arguments error");
	if (ft_strcmp(argv[1], "julia") != 0)
		return (1);
	
//	mlx_hook(screen.mlx, 2, 0, key_press, &screen);
	mlx_loop(screen.mlx);
	return (0);
}

