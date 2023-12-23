/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:01:59 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/23 21:07:16 by mllamas-         ###   ########.fr       */
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
	void	*coins;
	void	*goal;
	void	*ground;
	void	*wall;
	int		width;
	int		height;
}				t_data;

void	ft_exit(void);
void	check_map(t_data *game);

#endif
