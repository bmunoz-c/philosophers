/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:25:02 by bmunoz-c          #+#    #+#             */
/*   Updated: 2025/01/09 17:22:42 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (j);
}
/*
int	main(void)
{
	char s[] = "Holita";
	char s_2[] = "Holita";
	char d[20] = "X";
	char d_2[20] = "X";
	printf("%zu\n", ft_strlcpy(d, s, sizeof(char) * 3));
	printf("%zu\n", strlcpy(d_2, s_2, sizeof(char) * 3));
	return (0);
}
*/
