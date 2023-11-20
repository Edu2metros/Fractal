/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:56:27 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 11:05:27 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <math.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 200
# define LCG_MULTIPLIER 6364136223846793005U

typedef struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*paint;
	int				iter;
	int				height;
	int				width;
	int				color;
	int				fractal;
	char			*name;
	long double		min_x;
	long double		max_x;
	long double		min_y;
	long double		max_y;
	long double		x;
	long double		y;
	long double		zoom_x;
	long double		zoom_y;
	long double		real;
	long double		img;
	long double		min_z;
	long double		max_z;
	long double		param_real;
	long double		param_img;
	int				change_color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				xpos;
	int				ypos;
	int				color_validate;
	int				tricorn_or_mandelbrot;
}					t_fractal;

void				calculate(long double real, long double img,
						t_fractal *fractal);
int					mandelbrot_init(t_fractal *fractal, char *name);
int32_t				ft_bernstein_poly(int r, int g, int b, int i);
void				colorpixel(t_fractal *paint);
int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void				ft_key(void *param);
void				ft_zoom(void *param);
void				paint(t_fractal *set);
void				ft_scroll(double xdelta, double ydelta, void *param);
void				movement(t_fractal *fractal);
void				ft_keyhook(void *param);
double				media_movement(t_fractal *fractal);
int					julia_init(t_fractal *fractal, char **argv, int argc);
void				ft_keyhook(void *param);
void				reset_rgb(t_fractal *fractal);
void				updown(t_fractal *fractal);
void				left_right(t_fractal *fractal);
void				reset_rgb(t_fractal *fractal);
void				reset_fractal(t_fractal *fractal);
void				mouse_shift(t_fractal *fractal);
void				random_color(t_fractal *paint);
void				ft_message(int number);
int					choose_fractal(t_fractal *fractal, char **argv, int argc);
int					tricorn_init(t_fractal *fractal, char *name);

#endif