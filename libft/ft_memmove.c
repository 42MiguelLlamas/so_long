/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:53:41 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 12:25:06 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	while (dst == src || !len)
		return (dst);
	i = 0;
	ptrd = dst;
	ptrs = src;
	if (ptrd <= ptrs)
	{
		while (i < len)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		ptrd[len - 1 - i] = ptrs[len - 1 - i];
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
	ft_memmove(dst, src, 3);
	//memmove(dst, src, 3);
	printf("%s\n", dst);
	return (0);
}*/
