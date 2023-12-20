/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:18:14 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/27 17:19:17 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_check(char const c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	i = 0;
	while (ft_check(s1[i], set) == 1 && s1[i])
		i++;
	while (ft_check(s1[len - 1], set) == 1 && len > 0)
		len--;
	if (len <= i)
		return (ft_strdup(""));
	str = malloc((len - i + 1) * sizeof(char));
	if (!str)
		return (0);
	j = 0;
	while (i < len)
		str[j++] = (char)s1[i++];
	str[j] = '\0';
	return (str);
}
/*
int main(void)
{
	const char	set[] = "";
	const char	str[] = "";
	char		*res;

	res = ft_strtrim(str, set);
	printf("%s\n", res);
	free((void *)res);
	return (0);
}*/
