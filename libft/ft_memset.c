/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:24:28 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/18 12:00:03 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;
	unsigned char	*ptr;

	count = 0;
	ptr = b;
	while (count < len)
	{
		ptr[count] = c;
		count++;
	}
	return (b);
}
/*
int main(void)
{
	char cadena[] = "1234567";
	void	*ptr;

	ptr = &cadena[0];
	ft_memset(ptr + 2, 'a', 2);
	printf("%s\n", (char *)ptr);
	return (0);
}*/
