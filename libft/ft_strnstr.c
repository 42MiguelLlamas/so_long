/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:42:27 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/27 16:09:07 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ck;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		ck = 0;
		while (haystack[i + ck] == needle[ck] && i + ck < len && needle[ck])
			ck++;
		if (needle[ck] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	a[] = "aaabcabcd";
	const char	b[] = "cd";

	printf("%s\n", ft_strnstr(a, b, 8));
	printf("%s\n", strnstr(a, b, 8));
	return (0);
}*/
