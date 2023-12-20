/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:37 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 11:26:52 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	ptr1 = s1;
	ptr2 = s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	string1[] = "holaaa";
	char	string2[] = "holaa";
	const void *s1 = &string1[0];
	const void *s2 = &string2[0];

	printf("%d\n", ft_memcmp(s1, s2, 8));
	printf("%d\n", memcmp(s1, s2, 8));
	return (0);
}*/
