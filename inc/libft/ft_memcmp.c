/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:46:22 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:25 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) s1;
	s = (unsigned char *) s2;
	while (i < n)
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[20] = "Hello World";
	char	str2[20] = "Hola Mundo";

	printf("%d\n", ft_memcmp(str1, str2, sizeof(char) *5));
	printf("%d\n", memcmp(str1, str2, sizeof(char) *5));
	return (0);
}
*/
