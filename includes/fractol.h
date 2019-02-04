/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:01 by maheiden          #+#    #+#             */
/*   Updated: 2019/02/05 00:21:56 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"

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
	int					id;
	int					iteration;
	int					is_fixed;
	int					mouse_x;
	int					mouse_y;
	int					row_max;
	int					row;
	double				offset_x;
	double				offset_y;
	double				scale;
	t_img				img;
}				t_screen;

int				key_press(int key, t_screen *screen);
int				mouse_press(int button, int x, int y, t_screen *screen);
int				mouse_move(int x, int y, t_screen *screen);
int				close_this(void *param);

void			init_image(t_screen *screen);
void			set_pixel(t_screen *screen, int x, int y, int color);
void			clear_image(t_img *img);
int				set_color(t_screen *screen, int iteration);

void			display_error(int cond, char *str);
void			init(t_screen *screen, int flag);

void			mandelbrot(t_screen *screen);
void			julia(t_screen *screen);
void			tricorn(t_screen *screen);
void			burning_ship(t_screen *screen);
void			sierpinski(t_screen *screen);
void			barnsley(t_screen *screen);
void			sunflower(t_screen *screen);
#endif
