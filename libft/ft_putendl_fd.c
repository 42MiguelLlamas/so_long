/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:38:58 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/28 12:58:18 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "fcntl.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
int main(void)
{
	int fd;
	char s[] = "hola";
	fd = open("escribir", O_WRONLY);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
}*/
