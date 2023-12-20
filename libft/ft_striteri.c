/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:39:31 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 13:24:25 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	c;

	if (!s)
		return ;
	len = ft_strlen(s);
	c = 0;
	while (c < len)
	{
		f(c, s + c);
		c++;
	}
}
/*
void	itoupper(unsigned int c, char	*a)
{
	*a = *a - c;
}

int main(void)
{
	char a[] = "hola";
	ft_striteri(a, itoupper);
	printf("%s\n", a);
	return (0);
}*/
