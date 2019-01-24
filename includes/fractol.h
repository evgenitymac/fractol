/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheiden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:01 by maheiden          #+#    #+#             */
/*   Updated: 2019/01/24 21:46:39 by maheiden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# define WIDTH 2200
# define HEIGHT 1300

# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"

typedef	struct	s_complex
{
					double x;
					double y;
}				t_complex;

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
	int					x;
	int					y;
	double 				scale;
	t_complex			complex_num;
	t_img				img;
}				t_screen;

int		key_press(int key, t_screen *screen);

void	init_image(t_screen *screen);
void	set_pixel(t_screen *screen, int x, int y, int color);
void	clear_image(t_img *img);

t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_sqrt(t_complex a);
double		complex_mod(t_complex	a);
t_complex	map_point(t_screen *screen, int x, int y);

void	display_error(int cond, char *str);
void	init(t_screen *screen);

void	julia(int n, t_screen *screen);

#endif
