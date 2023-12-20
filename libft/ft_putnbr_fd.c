/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:59:43 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/28 12:58:07 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	nb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n / 10 != 0)
	{
		nb = n / 10;
		ft_putnbr_fd(nb, fd);
		write(fd, &(char){'0' + (n % 10)}, 1);
	}
	else
		write(fd, &(char){'0' + (n % 10)}, 1);
	return ;
}
/*
int main(void)
{
	int fd;

	fd = open("escribir", O_WRONLY);
	ft_putnbr_fd(-274783648, fd);
	close(fd);
	return (0);
}*/
