/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:01:59 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/28 14:31:47 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <mlx.h>

typedef struct s_data{
	char	*mapname;
	int		cols;
	int		rows;
	char	**map;
	char	**mapchecker;
	int		coinsnum;
	int		goalnum;
	int		playernum;
	int		playerx;
	int		playery;
	int		goalx;
	int		goaly;
	int		goalscheck;
	int		coinscheck;
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*goal;
	void	*ground;
	void	*wall;
	int		width;
	int		height;
	int		moves;
}				t_data;

void	ft_free(char **map);
void	ft_exit(void);
void	count_rows(t_data *game);
void	destroy_hook(t_data *game);
char	check_next_move(t_data *game, int x, int y);

int		key_hook(int keycode, t_data *game);
void	check_map_components(t_data *game);
void	check_map(t_data *game);
void	draw_map(t_data *game);
void	draw_element(t_data *game, int row, int col, char c);
#endif
