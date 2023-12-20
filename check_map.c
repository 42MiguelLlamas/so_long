/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:49:01 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/20 01:56:21 by mllamas-         ###   ########.fr       */
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
	int	i;

	if (ft_strlen(line) != len)
		ft_exit();
	if (line[0] != 49 || line[ft_strlen(line) - 1] != 49)
		ft_exit();
	i = 0;
	while (line[i])
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

	if (ft_strlen(line) != len || len < 4)
		ft_exit();
	i = 0;
	while (line[i])
	{
		if (line[i] != 49 && line[i] != 10)
			ft_exit();
		i++;
	}
}

void	check_map(int fd, t_data *game)
{
	char	*line;
	size_t	line_length;
	int		count;
	
	line = get_next_line(fd);
	line_length = ft_strlen(line);
	check_updown(line, line_length);
	count = 0;
	while (line)
	{
		check_middle(line, line_length);
		line = get_next_line(fd);
		i++;
	}
	
}
