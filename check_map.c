/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:49:01 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/20 11:15:57 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(void)
{
	write (1, "Error\n", 6);
	exit(0);
}

void	check_middle(char *line, size_t len)
{
	size_t	i;

	if (ft_strlen(line) != len)
		ft_exit();
	if (line[0] != 49 || line[len - 2] != 49)
		ft_exit();
	i = 0;
	while (i < len - 1)
	{
		if (!(line[i] == 48 || line[i] == 49 || line[i] == 67 || 
				line[i] == 69 || line[i] == 80))
			ft_exit ();
		i++;
	}
}

void	check_updown(char *line, size_t len)
{
	int	i;

	if (ft_strlen(line) != len || len < 3)
		ft_exit();
	i = 0;
	while (line[i])
	{
		if (line[i] != 49 && line[i] != 10)
			ft_exit();
		i++;
	}
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

void	fill_map(t_data *game, int lines, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit();
	game->map = (char **)malloc(sizeof(char *) * (lines + 1));
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

void print_map(char **map)
{
	int	i;

	i = 0;
    while (map[i])
   	{
        printf("%s", map[i]);
        i++;
    }
}

void	check_map(char *file, t_data *game)
{
	char	*line;
	size_t	line_length;
	int		count;
	int		fd;

	if (strncmp(".ber", file + ft_strlen(file) - 4, 4) != 0)
		ft_exit();
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit();
	line = get_next_line(fd);
	line_length = ft_strlen(line);
	check_updown(line, line_length);
	count = 0;
	while (line)
	{
		check_middle(line, line_length);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	fill_map(game, count, file);
	print_map(game->map);
	//check_elements(&game, count, line_length, file);
}
