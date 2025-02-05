/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:48:31 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 15:58:59 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needl, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needl)
		return ((char *) haystack);
	if (!*haystack)
		return (0);
	i = 0;
	while ((haystack[i] != '\0' && (i < len)))
	{
		j = 0;
		while (haystack[i + j] == needl[j] && (i + j) < len)
		{
			if (needl[j + 1] == '\0')
			{
				return ((char *) haystack + i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
int	main(void)
{
	char	s[20] = "Hello World";
	char	s2[20] = "World";
	printf ("%s\n", ft_strnstr(s, s2, 19));
	return (0);
}
*/
