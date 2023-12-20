/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:02:09 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 13:28:55 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		a;

	ptr = s;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == a)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return ((void *)0);
}
/*
int main(void)
{
	const char cad[] = "abcdef";
	const void *s;

	s = &cad[0];
	printf("%s\n", ft_memchr(s, 96, 8));
	printf("%s\n", memchr(s, 96, 8));
	return (0);
}*/
