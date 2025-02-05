/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:16 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/02/06 17:40:48 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			cont++;
		}
		while (s[i] && s[i] != c)
		{
			i++;
		}
	}
	return (cont);
}

static char	**ft_free(char **memory, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	start;
	char	**res;

	res = (char **) malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	x = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[x++] = ft_substr(s, start, (i - start + 1));
			if (!res[x - 1])
				return (ft_free(res, x - 1));
		}
		i++;
	}
	res[x] = NULL;
	return (res);
}
/*
__________________________________________________________________
word_count:
- localiza y devuelve el numero de palabras en la string.
 
free:
- libera todo lo asignado

fil_world: 
- asigna espaco suficiente para la palabra.
- copia la palabra en la memoria reservada.
- return la ppalabra asignada.
__________________________________________________________________
*/
/*
int main(void)
{
	char s[] = "hola,	que, tal";
	char c = ',';
	int i = 0;
	//printf("%d\n", ft_count_word(s, c));
	char **res = ft_split(s, c);
	while (res[i])
	{
		printf("%s\n",res[i]);
		i++;
	}
	return (0);
}
*/
