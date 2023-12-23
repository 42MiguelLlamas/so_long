/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:49:01 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/23 21:07:19 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(void)
{
	write (1, "Error\n", 6);
	exit(0);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	count_rows(t_data *game)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(game->mapname, O_RDONLY);
	if (fd < 0)
		ft_exit();
	line = get_next_line(fd);
	game->cols = (int)ft_strlen(line);
	count = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	game->rows = count;
	close(fd);
	if (game->cols < 3 || count < 3)
		ft_exit();
}

void	fill_map(t_data *game)
{
	int		fd;
	char	*line;
	int		i;

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

void	count_elements(char *mapi, t_data *game, int j)
{
	int	i;

	i = 0;
	while (mapi[i])
	{
		if (mapi[i] == 'C')
			game->coinsnum++;
		else if (mapi[i] == 'E')
		{
			game->goalx = i;
			game->goaly = j;
			game->goalnum++;
		}
		else if (mapi[i] == 'P')
		{
			game->playery = i;
			game->playerx= j;
			game->playernum++;
		}
		i++;
	}
}

void	check_first(char *line, int len, t_data *game)
{
	int	i;

	if ((int)ft_strlen(line) != len)
	{
		ft_free(game->map);
		ft_exit();
	}
	i = 0;
	while (i < len - 1)
	{
		if (line[i] != 49)
		{
			ft_free(game->map);
			ft_exit();
		}
		i++;
	}
}

void	check_middle(char *line, int len, t_data *game)
{
	int	i;

	if ((int)ft_strlen(line) != len)
	{
		ft_free(game->map);
		ft_exit();
	}
	if (line[0] != 49 || line[len - 2] != 49)
	{
		ft_free(game->map);
		ft_exit();
	}
	i = 0;
	while (i < len - 1)
	{
		if (!(line[i] == 48 || line[i] == 49 || line[i] == 67
				|| line[i] == 69 || line[i] == 80))
		{
			ft_free(game->map);
			ft_exit ();
		}
		i++;
	}
}

void	check_last(char *line, int len, t_data *game)
{
	int	i;

	if ((int)ft_strlen(line) != len && (int)ft_strlen(line) != len - 1)
	{
		ft_free(game->map);
		ft_exit();
	}
	i = 0;
	while (i < len - 1)
	{
		if (line[i] != 49)
		{
			ft_free(game->map);
			ft_exit();
		}
		i++;
	}
}

void	check_map_components(t_data *game)
{
	int	i;

	i = 0;	
	while (game->map[i])
	{
		count_elements(game->map[i], game, i);
		i++;
	}
	if (game->coinsnum < 1 || game->playernum != 1 || game->goalnum != 1)
	{
		ft_free(game->map);
		ft_exit();
	}
	i = 0;
	check_first(game->map[i++],game->cols, game);
	while (i < game->rows - 1)
	{
		check_middle(game->map[i], game->cols, game);
		i++;
	}
	check_last(game->map[i], game->cols, game);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	ft_freeint(int	**mapchecker, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(mapchecker[i]);
		i++;
	}
	free(mapchecker);
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
		game->mapchecker[i] = malloc((game->cols + 1) *  sizeof(char));
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
		return;
	if (!game->map[row][col])
		return;
	if (game->map[row][col] == 'C')
		game->coinscheck++;
	if (game->map[row][col] == 'E')
		game->goalscheck++;
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
	count_rows(game);
	fill_map(game);
	check_map_components(game);
	fill_mapchecker(game);
	check_mapchecker(game, game->playerx, game->playery);
	print_map(game->mapchecker);
	check_map_path(game);
	ft_free(game->mapchecker);
}
