/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:13:42 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:54 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	len = ft_strlen(dst);
	while (src[i] != '\0' && len < dstsize - 1)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	ret = 0;
	while(dst[i])
		i++;
	while(src[ret])
		ret++;
	if (dstsize <= i)
		ret = ret + dstsize;
	if (dstsize > i)
		ret = ret + i;
	while(src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ret);
}
*/
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = len_d;
	j = i;
	while (src[i - j] && i + 1 < dstsize)
	{
		dst[i] = src[i - j];
		i++;
	}
	dst[i] = '\0';
	if (dstsize < len_d)
	{
		return (len_s + dstsize);
	}
	else
		return (len_d + len_s);
}
*/
/*
int	main(void)
{
	char	src[] = "Munoz";
	char	dst[] = "Borja";

	printf("%lu\n", strlcat(dst, src, 4));
	return (0);
}
*/
