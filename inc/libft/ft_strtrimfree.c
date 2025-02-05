/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:45:36 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/11/18 19:41:17 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimfree(char *s1, char const *set, int free_s1)
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
	if (free_s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (res);
}

/*
int	main(void)

{
	printf("%s\n", ft_strtrim("abababHolaMiriambabab", "ab"));
	return (0);
}
*/
