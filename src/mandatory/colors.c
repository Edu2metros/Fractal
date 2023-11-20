/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:56:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 11:31:49 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_bernstein_poly(int r, int g, int b, int i)
{
	double	t;
	int32_t	color;

	t = 1.0 * i / MAX_ITER;
	color = ft_pixel(r * 8.5 * (1 - t) * (1 - t) * (1 - t) * t, g * 15 * (1 - t)
			* (1 - t) * t * t, b * 9 * (1 - t) * t * t * t, 255);
	return (color);
}

void	colorpixel(t_fractal *paint)
{
	long double	interporlate;

	interporlate = paint->iter / MAX_ITER;
	if (interporlate <= 0.2)
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_pixel(0, 0, 0, 255));
	if (paint->iter >= 0.2 && paint->iter < 0.4)
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_bernstein_poly(80,
				180, 255, paint->iter));
	if (paint->iter >= 0.4 && paint->iter < 0.6)
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_bernstein_poly(190,
				180, 255, paint->iter));
	if (paint->iter >= 0.6 && paint->iter < 0.8)
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_bernstein_poly(255,
				50, 255, paint->iter));
	else
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_bernstein_poly(255,
				255, 255, paint->iter));
}

void	random_color(t_fractal *paint)
{
	if (paint->iter == MAX_ITER)
		mlx_put_pixel(paint->paint, paint->x, paint->y, ft_pixel(0, 0, 0, 255));
	else
		mlx_put_pixel(paint->paint, paint->x, paint->y,
			ft_bernstein_poly(paint->r, paint->g, paint->b, paint->iter));
}
