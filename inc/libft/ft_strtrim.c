/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:57:33 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/17 18:41:44 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	start;
	size_t	end;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (i < len && (ft_strchr(set, s1[len])))
		len--;
	start = i;
	end = len;
	res = ft_substr(s1, start, (end - start) + 1);
	if (!res)
		return (NULL);
	return (res);
}

/*
int	main(void)

{
	printf("%s\n", ft_strtrim("abababHolaMiriambabab", "ab"));
	return (0);
}
*/
