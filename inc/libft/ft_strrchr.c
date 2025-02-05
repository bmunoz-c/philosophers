/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:31:01 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/25 18:14:39 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*
int	main(void)
{
	char	s[20] = "Hello World";
	char	s2[20] = "Hello World";

	printf("%s\n", ft_strrchr(s, 'o'));
	printf("%s\n", strrchr(s2, 'o'));
	return (0);
}
*/
