/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:04:31 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 12:38:18 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	calculate(long double real, long double img, t_fractal *fractal)
{
	long double	r;
	long double	i;
	long double	r2;
	long double	i2;

	fractal->iter = 0;
	r = real;
	i = img;
	while (++fractal->iter < MAX_ITER)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 4.0)
			break ;
		if (fractal->fractal == 1)
		{
			i = 2 * r * i + fractal->param_img;
			r = r2 - i2 + fractal->param_real;
		}
		if (fractal->fractal == 0)
		{
			i = fractal->tricorn_or_mandelbrot * r * i + img;
			r = r2 - i2 + real;
		}
	}
}

double	media_movement(t_fractal *fractal)
{
	double	mov;

	mov = (0.2 / (1.0 / (fractal->max_x - fractal->min_x)));
	if (mov > 0.5)
		return (0.5);
	return (mov);
}
