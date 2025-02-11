/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:04:16 by bmunoz-c          #+#    #+#             */
/*   Updated: 2025/01/25 07:12:31 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if free_flag = 1, free s1.
//if free_flag = 2, free s2.
//if free_flag = 3, free s1 and s2.
char	*ft_strjoin_f(char *s1, char *s2, int free_flag)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (NULL);
	if (s1)
		ft_strlcpy(join, s1, s1len + 1);
	if (s2)
		ft_strlcpy(join + s1len, s2, s2len + 1);
	if (free_flag == 1 || free_flag == 3)
		free_ptr(s1);
	if (free_flag == 2 || free_flag == 3)
		free_ptr(s2);
	return (join);
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
