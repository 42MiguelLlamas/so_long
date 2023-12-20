/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:41:35 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/18 11:58:39 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned int	count;
	unsigned char	*ptr;

	count = 0;
	ptr = b;
	while (count < len)
	{
		ptr[count] = 0;
		count++;
	}
}
/*
int main(void)
{
	char cadena[] = "1234567";
	void    *ptr;

	ptr = &cadena[0];
	ft_bzero(ptr + 2, 2);
	printf("%s\n", ptr);
	return (0);
}
*/
