/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:37:13 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 18:34:37 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;
	unsigned char	len;

	i = 0;
	b = (unsigned char *) s;
	len = (unsigned char) c;
	while (i < n)
	{
		if (b[i] != len)
			i++;
		else
			return (&b[i]);
	}
	return (0);
}
/*
int	main(void)
{
	char str[20] = "Hola mundo";
	char str2[20] = "m";
	printf("%d\n", memchr(str, str2, 'n'));
	return (0);
}
*/
