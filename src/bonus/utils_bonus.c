/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:06:35 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 11:06:34 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	julia_init(t_fractal *fractal, char **argv, int argc)
{
	if (argc == 4)
	{
		fractal->name = argv[1];
		fractal->iter = 0;
		fractal->min_x = -1.5;
		fractal->max_x = 0.5;
		fractal->min_y = -1.0;
		fractal->max_y = 1.0;
		fractal->param_real = ft_atof(argv[2]);
		fractal->param_img = ft_atof(argv[3]);
		fractal->iter = -1;
		fractal->fractal = 1;
		fractal->color_validate = 0;
		fractal->change_color = 0;
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_message(1);
		return (EXIT_FAILURE);
	}
}

int	mandelbrot_init(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->iter = 0;
	fractal->min_x = -2.0;
	fractal->max_x = 1.0;
	fractal->min_y = -1.5;
	fractal->max_y = 1.5;
	fractal->param_img = 0;
	fractal->param_real = 0;
	fractal->fractal = 0;
	fractal->change_color = 0;
	fractal->r = 255;
	fractal->g = 255;
	fractal->b = 255;
	fractal->xpos = 0;
	fractal->ypos = 0;
	fractal->color_validate = 0;
	fractal->tricorn_or_mandelbrot = 2;
	return (0);
}

void	reset_rgb(t_fractal *fractal)
{
	fractal->r = 255;
	fractal->g = 255;
	fractal->b = 255;
	fractal->color_validate = 0;
}

void	reset_fractal(t_fractal *fractal)
{
	fractal->min_x = -2.0;
	fractal->max_x = 1.0;
	fractal->min_y = -1.5;
	fractal->max_y = 1.5;
}

int	tricorn_init(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->iter = 0;
	fractal->min_x = -2.0;
	fractal->max_x = 1.0;
	fractal->min_y = -1.5;
	fractal->max_y = 1.5;
	fractal->param_img = 0;
	fractal->param_real = 0;
	fractal->fractal = 0;
	fractal->change_color = 0;
	fractal->r = 255;
	fractal->g = 255;
	fractal->b = 255;
	fractal->xpos = 0;
	fractal->ypos = 0;
	fractal->color_validate = 0;
	fractal->tricorn_or_mandelbrot = -2;
	return (0);
}
