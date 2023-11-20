/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:59:02 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 19:12:46 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	updown(t_fractal *fractal)
{
	long double	mov;

	mov = 0;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_W))
	{
		mov = media_movement(fractal);
		fractal->min_y -= mov;
		fractal->max_y -= mov;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_S))
	{
		mov = media_movement(fractal);
		fractal->min_y += mov;
		fractal->max_y += mov;
	}
}

void	left_right(t_fractal *fractal)
{
	long double	mov;

	mov = 0;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_A))
	{
		mov = media_movement(fractal);
		fractal->min_x -= mov;
		fractal->max_x -= mov;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_D))
	{
		mov = media_movement(fractal);
		fractal->min_x += mov;
		fractal->max_x += mov;
	}
}

void	ft_zoom(void *param)
{
	t_fractal	*fractal;
	long double	zoom_factor;
	long double	center_x;
	long double	center_y;

	fractal = param;
	zoom_factor = 0.8;
	center_x = (fractal->min_x + fractal->max_x) / 2.0;
	center_y = (fractal->min_y + fractal->max_y) / 2.0;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_ADD)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_EQUAL))
	{
		fractal->min_x = center_x - (center_x - fractal->min_x) * zoom_factor;
		fractal->max_x = center_x + (fractal->max_x - center_x) * zoom_factor;
		fractal->min_y = center_y - (center_y - fractal->min_y) * zoom_factor;
		fractal->max_y = center_y + (fractal->max_y - center_y) * zoom_factor;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_SUBTRACT)
		|| mlx_is_key_down(fractal->mlx, MLX_KEY_MINUS))
	{
		fractal->min_x = center_x - (center_x - fractal->min_x) / zoom_factor;
		fractal->max_x = center_x + (fractal->max_x - center_x) / zoom_factor;
		fractal->min_y = center_y - (center_y - fractal->min_y) / zoom_factor;
		fractal->max_y = center_y + (fractal->max_y - center_y) / zoom_factor;
	}
}
