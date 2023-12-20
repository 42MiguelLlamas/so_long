/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:05:03 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/19 11:36:33 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*b;
	unsigned char	*ptr;
	size_t			i;

	i = count * size;
	b = malloc(i);
	if (!b)
		return (b);
	ptr = b;
	while (i > 0)
	{
		ptr[i - 1] = 0;
		i--;
	}
	return ((void *)ptr);
}
/*
int main(void)
{
	void	*str = ft_calloc(3,3);
	void	*ctr = calloc(3,3);
	if (str == NULL || ctr == NULL)
	{
		perror("La asignación de memoria falló");
		return (1);
	}
	printf("%s\n", str);
	printf("%s\n", ctr);
	free(str);
	free(ctr);
	return (0);
}*/
