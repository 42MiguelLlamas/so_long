/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:59:51 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/19 20:36:00 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 100;
	while (i++ < 200)
	{
		j = 50;
		while (j++ < 200)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	closfe(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void destroy_hook(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0); // Termina el programa
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, closfe, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0L, (void *)destroy_hook, &vars);
	mlx_loop(vars.mlx);
}
