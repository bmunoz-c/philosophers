/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:34:37 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/21 17:50:43 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
int	main(void)
{
	char	s[] = "ABCDEFG";

	ft_bzero(s, 5 * sizeof(char));
	printf("%s", s);
	return (0);
}
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char str[] = "Hola mundo";
	char str1[20] = "Hola mundo";
	printf("%s\n", ft_bzero(str, sizeof(char)));
	printf("%s\n", bzero(str, sizeof(char)));
	return (0);
}
*/
