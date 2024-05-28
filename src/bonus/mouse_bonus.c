/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:51:17 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/05/28 15:11:50 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	double		zoom_factor;

	f = param;
	(void)xdelta;
	zoom_factor = 1.1;
	mlx_get_mouse_pos(f->mlx, &f->xpos, &f->ypos);
	f->zoom_x = f->min_x + f->xpos * ((f->max_x - f->min_x) / WIDTH);
	f->zoom_y = f->min_y + f->ypos * ((f->max_y - f->min_y) / HEIGHT);
	if (ydelta > 0)
	{
		f->min_x = f->zoom_x - (1.0 / zoom_factor) * (f->zoom_x - f->min_x);
		f->max_x = f->zoom_x + (1.0 / zoom_factor) * (f->max_x - f->zoom_x);
		f->min_y = f->zoom_y - (1.0 / zoom_factor) * (f->zoom_y - f->min_y);
		f->max_y = f->zoom_y + (1.0 / zoom_factor) * (f->max_y - f->zoom_y);
	}
	if (ydelta < 0)
	{
		f->min_x = f->zoom_x - zoom_factor * (f->zoom_x - f->min_x);
		f->max_x = f->zoom_x + zoom_factor * (f->max_x - f->zoom_x);
		f->min_y = f->zoom_y - zoom_factor * (f->zoom_y - f->min_y);
		f->max_y = f->zoom_y + zoom_factor * (f->max_y - f->zoom_y);
	}
}

void	mouse_shift(t_fractal *fractal)
{
	long double	media_x;
	long double	media_y;
	long double	relative_x;
	long double	relative_y;

	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_SHIFT))
	{
		mlx_get_mouse_pos(fractal->mlx, &fractal->xpos, &fractal->ypos);
		media_x = fractal->max_x - fractal->min_x;
		media_y = fractal->max_y - fractal->min_y;
		relative_x = (double)fractal->xpos / WIDTH;
		relative_y = (double)fractal->ypos / HEIGHT;
		fractal->param_real = fractal->min_x + (relative_x * 0.85) * media_x;
		fractal->param_img = fractal->min_y + (relative_y * 0.85) * media_y;
	}
}
