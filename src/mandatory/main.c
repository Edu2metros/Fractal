/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:04:26 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 12:36:29 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	paint(t_fractal *set)
{
	set->x = 0;
	set->y = 0;
	while (set->x < WIDTH)
	{
		set->y = 0;
		while (set->y < HEIGHT)
		{
			set->real = set->min_x + set->x * (set->max_x - set->min_x) / WIDTH;
			set->img = set->min_y + set->y * (set->max_y - set->min_y) / HEIGHT;
			calculate(set->real, set->img, set);
			if (set->color_validate == 0)
				colorpixel(set);
			else
				random_color(set);
			set->y++;
		}
		set->x++;
	}
	mlx_image_to_window(set->mlx, set->paint, 0, 0);
}

static uint32_t	rdm_color(int32_t seed)
{
	static uint32_t	result;

	result = result + (uint64_t)rdm_color * seed;
	return (result);
}

void	change_color(t_fractal *fractal)
{
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_C))
	{
		fractal->color_validate = 1;
		fractal->r = rdm_color(0XFFFFFFF) % 255;
		fractal->g = rdm_color(0XFFFFFFF) % 255;
		fractal->b = rdm_color(0XFFFFFFF) % 255;
	}
}

void	ft_keyhook(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_V))
		reset_rgb(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_R))
		reset_fractal(fractal);
	paint(fractal);
	change_color(fractal);
	updown(fractal);
	left_right(fractal);
	ft_zoom(fractal);
}

int32_t	main(int argc, char *argv[])
{
	t_fractal	f;
	mlx_t		*mlx;
	int			validator;

	if (argc == 1)
	{
		ft_message(3);
		return (EXIT_FAILURE);
	}
	validator = choose_fractal(&f, argv, argc);
	if (validator)
		return (EXIT_FAILURE);
	mlx = mlx_init(WIDTH, HEIGHT, f.name, false);
	if (!mlx)
		return (EXIT_FAILURE);
	f.mlx = mlx;
	f.paint = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!f.paint || (mlx_image_to_window(f.mlx, f.paint, 0, 0) < 0))
		return (EXIT_FAILURE);
	ft_message(0);
	mlx_scroll_hook(mlx, ft_scroll, &f);
	mlx_loop_hook(mlx, ft_keyhook, &f);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
