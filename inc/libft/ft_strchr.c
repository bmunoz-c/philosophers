/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:35:20 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 18:29:15 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char) c)
		i++;
	if (s[i] == '\0' && (char) c != 0)
		return (0);
	else
		return ((char *) &s[i]);
}
/*
int	main(void)
{
	char str[] = "Hello World";
	char str_2[] = "Hello World";

	printf("%p\n", ft_strchr(str, 'l'));
	printf("%p\n", strchr(str_2, 'l'));
	return (0);
}
*/
