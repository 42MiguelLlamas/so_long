/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:51:10 by mllamas-          #+#    #+#             */
/*   Updated: 2023/12/20 00:45:09 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
char	*ft_freeleft(char **left);
void	*ft_callocc(size_t count, size_t size);
char	*ft_strchrr(char *ptr, int c);
size_t	ft_strleng(char *s);
char	*ft_strjoinn(char *s1, char *s2);
int		output_len(char *str);
int		left_len(char *str);
char	*ft_freeleft(char **left);

#endif
