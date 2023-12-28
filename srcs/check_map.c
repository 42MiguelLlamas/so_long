/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:49:01 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:11 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_map(t_data *game)
{
	int		fd;
	char	*line;
	int		i;

	count_rows(game);
	if (game->rows < 3)
		ft_exit();
	fd = open(game->mapname, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		ft_exit();
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		if (!game->map[i])
		{
			ft_free(game->map);
			ft_exit();
		}
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = line;
}

void	fill_mapchecker(t_data *game)
{
	int	i;
	int	j;

	game->mapchecker = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->mapchecker)
	{
		ft_free(game->map);
		ft_exit();
	}
	i = 0;
	while (i < game->rows)
	{
		game->mapchecker[i] = malloc((game->cols + 1) * sizeof(char));
		if (!game->mapchecker[i])
		{
			ft_free(game->mapchecker);
			ft_free(game->map);
			ft_exit();
		}
		j = -1;
		while (j++ < game->cols)
			game->mapchecker[i][j] = game->map[i][j];
		i++;
	}
	game->mapchecker[i] = NULL;
}

void	check_mapchecker(t_data *game, int row, int col)
{
	if (game->map[row][col] == '1' || game->mapchecker[row][col] == '1')
		return ;
	if (!game->map[row][col])
		return ;
	if (game->map[row][col] == 'C')
		game->coinscheck++;
	if (game->map[row + 1][col] == 'E' || game->map[row - 1][col] == 'E' ||
			game->map[row][col + 1] == 'E' || game->map[row][col - 1] == 'E')
		game->goalscheck++;
	if (game->map[row + 1][col] == 'E')
		game->map[row + 1][col] = '1';
	if (game->map[row - 1][col] == 'E')
		game->map[row - 1][col] = '1';
	if (game->map[row][col - 1] == 'E')
		game->map[row][col - 1] = '1';
	if (game->map[row][col + 1] == 'E')
		game->map[row][col + 1] = '1';
	game->mapchecker[row][col] = '1';
	check_mapchecker(game, row + 1, col);
	check_mapchecker(game, row - 1, col);
	check_mapchecker(game, row, col + 1);
	check_mapchecker(game, row, col - 1);
}

void	check_map_path(t_data *game)
{
	if (game->goalscheck != game->goalnum)
	{
		ft_free(game->mapchecker);
		ft_free(game->map);
		ft_exit();
	}
	if (game->coinscheck != game->coinsnum)
	{
		ft_free(game->mapchecker);
		ft_free(game->map);
		ft_exit();
	}
}

void	check_map(t_data *game)
{
	game->coinsnum = 0;
	game->playernum = 0;
	game->goalnum = 0;
	game->coinscheck = 0;
	game->goalscheck = 0;
	fill_map(game);
	check_map_components(game);
	fill_mapchecker(game);
	check_mapchecker(game, game->playery, game->playerx);
	check_map_path(game);
	ft_free(game->mapchecker);
}
