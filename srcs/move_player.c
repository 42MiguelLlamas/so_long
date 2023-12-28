/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:24:57 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:36 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *game)
{
	char	a;

	a = check_next_move(game, game->playerx, game->playery - 1);
	if (a == '1' || a == 'E')
		return ;
	draw_element(game, game->playery, game->playerx, '0');
	draw_element(game, game->playery - 1, game->playerx, 'P');
	game->map[game->playery - 1][game->playerx] = 'P';
	game->playery--;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
}

void	move_down(t_data *game)
{
	char	a;

	a = check_next_move(game, game->playerx, game->playery + 1);
	if (a == '1' || a == 'E')
		return ;
	draw_element(game, game->playery, game->playerx, '0');
	draw_element(game, game->playery + 1, game->playerx, 'P');
	game->map[game->playery + 1][game->playerx] = 'P';
	game->playery++;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
}

void	move_left(t_data *game)
{
	char	a;

	a = check_next_move(game, game->playerx - 1, game->playery);
	if (a == '1' || a == 'E')
		return ;
	draw_element(game, game->playery, game->playerx, '0');
	draw_element(game, game->playery, game->playerx - 1, 'P');
	game->map[game->playery][game->playerx - 1] = 'P';
	game->playerx--;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
}

void	move_right(t_data *game)
{
	char	a;

	a = check_next_move(game, game->playerx + 1, game->playery);
	if (a == '1' || a == 'E')
		return ;
	draw_element(game, game->playery, game->playerx, '0');
	draw_element(game, game->playery, game->playerx + 1, 'P');
	game->map[game->playery][game->playerx + 1] = 'P';
	game->playerx++;
	game->moves++;
	ft_printf("Movimientos: %d\n", game->moves);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}
