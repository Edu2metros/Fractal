/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:30:58 by eddos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 11:36:15 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	choose_fractal(t_fractal *fractal, char **argv, int argc)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		argv[1][i] = ft_tolower(argv[1][i]);
		i++;
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
		return (mandelbrot_init(fractal, argv[1]));
	else if (!ft_strncmp(argv[1], "julia", 5) && argc >= 2)
		return (julia_init(fractal, argv, argc));
	else
		ft_message(3);
	return (EXIT_FAILURE);
}

void	ft_message(int number)
{
	static char	*message[4] = {
		"Hello and welcome to my program exploring the beauty of fractals!\n"
		"You can navigate using the arrow keys,"
		" zoom in and out with + and - or the mouse scroll.\n"
		"Press C to change to a random color, "
		"V to return to the original color,"
		" and R to reset to the initial fractal state.\n"
		"I hope you enjoy this adventure!",
		"Uh-oh! :(\n"
		"The Julia set needs two parameters to function.\n"
		"Please type: ./fractol julia -0.8 0.156\n",
		"Please write:"
		"./fractol mandelbrot"
		"or ./fractol julia -0.8 0.156\n",
		"Fractal not found. "
		"Please type: ./fractal"
		"(mandelbrot/julia -0.8 0.156)\n"
	};

	ft_putstr_fd(message[number], 1);
}
