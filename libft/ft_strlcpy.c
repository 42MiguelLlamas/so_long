/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:37:43 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 13:07:58 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	const char a[] = "123456";
	char b[] = "ggggg";

	const char *src = &a[0];
	char *dest = &b[0];
	//printf("%zu\n", ft_strlcpy(dest, src, 5));
	//printf("%c\n", dest[4]);
	printf("%zu\n", strlcpy(dest, src, 5));
	printf("%c\n", dest[4]);
	return (0);
}*/
