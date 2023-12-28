/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:13:04 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:40:05 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			game->playery = j;
			game->playerx = i;
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
	check_first(game->map[i++], game->cols, game);
	while (i < game->rows - 1)
	{
		check_middle(game->map[i], game->cols, game);
		i++;
	}
	check_last(game->map[i], game->cols, game);
}
