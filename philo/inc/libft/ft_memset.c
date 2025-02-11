/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:23 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/21 17:49:48 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[15] = "abracadabra";
	char	str1[15] = "abracadabra";
	printf("%s\n", ft_memset(str, 'X', sizeof(char) * 4));
	printf("%s\n", memset(str1, 'X', sizeof(char) * 4));
	return (0);
}
*/
