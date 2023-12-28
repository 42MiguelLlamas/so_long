/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:59:51 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 15:23:59 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_data	game;
	
	atexit(leaks);
	if (argc != 2)
		ft_exit();
	if (strncmp(".ber", argv[1] + ft_strlen(argv[1]) - 4, 4) != 0)
		ft_exit();
	game.mapname = argv[1];
	game.height = 128;
	game.width = 128;
	check_map(&game);
	game.mlx = mlx_init();
	mlx_do_key_autorepeaton(game.mlx);
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, (void *)key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)destroy_hook, &game);
	mlx_loop(game.mlx);
}
