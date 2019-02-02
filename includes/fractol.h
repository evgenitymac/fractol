/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:01 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/02 17:41:53 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"

typedef	struct	s_img
{
	void				*image;
	char				*ptr;
	int					bpp;
	int					size_line;
	int					endian;
}				t_img;

typedef	struct	s_screen
{
	void				*mlx;
	void				*win;
	int				id;
	int				iteration;
	double				offset_x;
	double				offset_y;
	int					x;
	int					y;
	double 				scale;
	t_img				img;
}				t_screen;

int		key_press(int key, t_screen *screen);
int		mouse_move(int button, int x, int y, t_screen *screen);
void	init_image(t_screen *screen);
void	set_pixel(t_screen *screen, int x, int y, int color);
void	clear_image(t_img *img);

void	display_error(int cond, char *str);
void	init(t_screen *screen, int flag);

void	julia(t_screen *screen);
void	mandelbrot(t_screen *screen);
void	tricorn(t_screen *screen);
void	burning_ship(t_screen *screen);
void	sierpinski(t_screen *screen);

#endif
