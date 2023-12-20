/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:22:39 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/18 12:03:11 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	j;

	dest_len = 0;
	src_len = 0;
	j = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0 || dstsize <= dest_len)
		return (src_len + dstsize);
	while (dest_len + 1 < dstsize && src[j] != '\0')
	{
		dst[dest_len] = src[j];
		dest_len++;
		j++;
	}
	dst[dest_len] = '\0';
	return (src_len + dest_len - j);
}
/*
int	main(void)
{
	char	a[] = "123";
	char	b[] = "e";
	char	*src;
	char	*dest;

	src = &b[0];
	dest = &a[0];
	//printf("%zu\n", ft_strlcat(dest, src, 4));
	//printf("%s\n", dest);
	printf("%zu\n", strlcat(dest, src, 4));
	printf("%s\n", dest);
	return (0);
}*/
