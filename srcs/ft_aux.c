/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:07:14 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:25 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	destroy_hook(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

char	check_next_move(t_data *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->coinscheck++;
		return ('C');
	}
	else if (game->map[y][x] == '0')
		return ('0');
	else if (game->map[y][x] == '1')
		return ('1');
	else if (game->map[y][x] == 'E' && game->coinscheck != game->coinsnum)
		return ('E');
	else if (game->map[y][x] == 'P')
	{
		game->map[y][x] = '0';
		return ('0');
	}
	ft_free(game->map);
	exit(1);
	return (0);
}
