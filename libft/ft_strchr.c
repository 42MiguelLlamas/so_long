/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:32:39 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 13:37:33 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	a;
	int		num;

	ptr = (char *)s;
	num = 0;
	a = (char)c;
	while (*ptr != a && *ptr)
		ptr++;
	if (*ptr != a)
		return (0);
	return (ptr);
}
/*
int main(void)
{
	const char cad[] = "abcdef";
	const char *s;

	s = &cad[0];
	printf("%s\n", ft_strchr(s, 'b' + 256));
	printf("%s\n", strchr(s, 'b' + 256));
	return(0);
}*/
