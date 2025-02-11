/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:04:16 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/30 18:40:47 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	p = (char *) malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[j] = s1[i];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main(void)
{
	char s1[] = "Hola ";
	char s2[] = "mundo!";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
