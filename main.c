/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:59:51 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/27 15:30:11 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 13)
	{
		draw_element(game, game->playerx, game->playery, '1');
		draw_element(game, game->playerx, game->playery - 1, 'P');
	}
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

void	destroy_hook(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0); // Termina el programa
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_exit();
	if (strncmp(".ber", argv[1] + ft_strlen(argv[1]) - 4, 4) != 0)
		ft_exit();
	game.mapname = argv[1];
	game.height = 128;
	game.width = 128;
	check_map(&game);
	game.mlx = mlx_init();
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)destroy_hook, &game);
	mlx_loop(game.mlx);
}
