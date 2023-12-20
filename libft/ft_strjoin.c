/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:01:06 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/18 13:44:32 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (str);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	const char	a[] = "hola";
	const char	b[] = "adios";
	char	*str;

	str = ft_strjoin(a, b);
	printf("%s\n", str);
	return (0);
}*/
