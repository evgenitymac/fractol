/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:24:15 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 22:37:27 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init(t_screen *screen, int flag)
{
	if (flag != 1)
	{
		screen->mlx = mlx_init();
		screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "fractol");
		init_image(screen);
	}
	screen->scale = 1;
	screen->offset_x = 0;
	screen->offset_y = 0;
	screen->mouse_x = 0;
	screen->mouse_y = 0;
	screen->iteration = 10;
	screen->row_max = HEIGHT;
	screen->row = 0;
}

void			display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}

static void		display_fractals_name(void)
{
	ft_putstr("usage : fractol [flactals]\n  fractals : \n"
			" --> mandelbrot\n --> julia\n --> burning-ship\n"
			" --> tricorn\n --> sierpinski\n --> barnsley\n"
			" --> sun\n");
	exit(0);
}

static void		choose_fractal(t_screen *screen, char **argv)
{
	if (ft_strcmp(ft_tolower_str(argv[1]), "burning-ship") == 0)
	{
		screen->id = 3;
		render(screen, burning_ship);
	}
	else if (ft_strcmp(ft_tolower_str(argv[1]), "sierpinski") == 0)
	{
		screen->id = 4;
		sierpinski(screen);
	}
	else if (ft_strcmp(ft_tolower_str(argv[1]), "barnsley") == 0)
	{
		screen->id = 5;
		barnsley(screen);
	}
	else if (ft_strcmp(ft_tolower_str(argv[1]), "sun") == 0)
	{
		screen->id = 6;
		sunflower(screen);
	}
	else
		display_fractals_name();
}

int				main(int argc, char **argv)
{
	t_screen	*screen;

	screen = (t_screen *)ft_memalloc(sizeof(t_screen));
	init(screen, 0);
	display_error(argc != 2, "arguments error, try to tap something");
	if (ft_strcmp(ft_tolower_str(argv[1]), "julia") == 0)
	{
		screen->id = 0;
		render(screen, julia);
	}
	else if (ft_strcmp(ft_tolower_str(argv[1]), "mandelbrot") == 0)
	{
		screen->id = 1;
		render(screen, mandelbrot);
	}
	else if (ft_strcmp(ft_tolower_str(argv[1]), "tricorn") == 0)
	{
		screen->id = 2;
		render(screen, tricorn);
	}
	else
		choose_fractal(screen, argv);
	start_sniff(screen);
	mlx_loop(screen->mlx);
	return (0);
}
