/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:20:06 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 13:22:36 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*str;
	size_t		i;

	len = ft_strlen(s);
	i = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > i)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char	itoupper(unsigned int c, char	a)
{
	return (a - c);
}

int main(void)
{
	char a[] = "hola";
	printf("%s\n", ft_strmapi(a, itoupper));
	return (0);
}*/
