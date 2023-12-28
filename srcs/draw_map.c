/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:15:56 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:43:51 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_init(t_data *game)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "sprites/ground.xpm",
			&game->width, &game->height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm",
			&game->width, &game->height);
	game->goal = mlx_xpm_file_to_image(game->mlx, "sprites/goal.xpm",
			&game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
			&game->width, &game->height);
}

void	draw_element(t_data *game, int row, int col, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
			col * game->width, row * game->height);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->goal,
			col * game->width, row * game->height);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->ground,
			col * game->width, row * game->height);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			col * game->width, row * game->height);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			col * game->width, row * game->height);
}

void	ft_display(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
				draw_element(game, i, j, 'P');
			else if (game->map[i][j] == '1')
				draw_element(game, i, j, '1');
			else if (game->map[i][j] == 'C')
				draw_element(game, i, j, 'C');
			else if (game->map[i][j] == '0')
				draw_element(game, i, j, '0');
			else if (game->map[i][j] == 'E')
				draw_element(game, i, j, 'E');
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *game)
{
	game->map[game->goaly][game->goalx] = 'E';
	game->coinscheck = 0;
	game->moves = 0;
	ft_init(game);
	game->win = mlx_new_window(game->mlx, (game->cols - 1) * game->height,
			game->rows * game->width, "solong");
	ft_display(game);
}
