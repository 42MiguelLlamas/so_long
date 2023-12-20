/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:02:16 by mllamas-          #+#    #+#             */
/*   Updated: 2023/09/13 16:01:10 by mllamas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	a;
	int		num;

	ptr = (char *)s;
	num = 0;
	a = (char)c;
	while (ptr[num])
		num++;
	while (num != -1 && ptr[num] != a)
		num--;
	if (num == -1)
		return (0);
	return (ptr + num);
}
/*
int main(void)
{
	const char cad[] = "abcdaefg";
	const char *s;
	int c = 97;

	s = &cad[0];
	//printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
	return(0);
}*/
