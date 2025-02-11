/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:45:04 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:47 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s[20] = "Hello World";
	char	s2[20] = "Hola mundo";
	printf("%d\n", ft_strncmp(s, s2, 5));
	return (0);
}

	char	str1[] = "Hello";
	char	str2[] = "Hello";
	int	result = ft_strcmp(str1, str2);
	if (result < 0)
		printf("str1 < str2\n");
	else if (result > 0)
		printf("str1 > str2\n");
	else
		printf("str1 = str2\n");
	return (0);
}
*/
