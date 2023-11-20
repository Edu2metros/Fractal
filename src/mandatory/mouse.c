/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:18:48 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 11:32:30 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		zoom_factor;
	double		center_x;
	double		center_y;

	fractal = param;
	zoom_factor = 0.8;
	center_x = (fractal->min_x + fractal->max_x) / 2.0;
	center_y = (fractal->min_y + fractal->max_y) / 2.0;
	if (ydelta > 0 || xdelta > 0)
	{
		fractal->min_x = center_x - (center_x - fractal->min_x) * zoom_factor;
		fractal->max_x = center_x + (fractal->max_x - center_x) * zoom_factor;
		fractal->min_y = center_y - (center_y - fractal->min_y) * zoom_factor;
		fractal->max_y = center_y + (fractal->max_y - center_y) * zoom_factor;
	}
	if (ydelta < 0 || xdelta < 0)
	{
		fractal->min_x = center_x - (center_x - fractal->min_x) / zoom_factor;
		fractal->max_x = center_x + (fractal->max_x - center_x) / zoom_factor;
		fractal->min_y = center_y - (center_y - fractal->min_y) / zoom_factor;
		fractal->max_y = center_y + (fractal->max_y - center_y) / zoom_factor;
	}
}
