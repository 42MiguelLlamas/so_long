/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:27:14 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/27 14:00:12 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	i = 0;
	ptrd = dst;
	ptrs = (unsigned char *)src;
	while (dst == src || !n)
		return (dst);
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char a[] = "";
	char b[] = "";

	void *src = &a[0];
	void *dst = &b[0];
	ft_memcpy(dst, src, 3);
	printf("%s\n", dst);
	memcpy(dst, src, 3);
	printf("%s\n", dst);
	return (0);
}*/
