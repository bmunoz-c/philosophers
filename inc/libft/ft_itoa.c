/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:41:04 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/02/06 21:39:03 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(long nbr)
{
	size_t	counter;

	counter = 0;
	if (nbr < 0)
	{
		counter++;
		nbr = -nbr;
	}
	if (nbr == 0)
		counter++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_strres(int len, long nb)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	if (nb == 0)
		res[0] = 48;
	while (nb > 0)
	{
		res[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*res;

	nbr = n;
	len = ft_int_len(nbr);
	res = ft_strres(len, nbr);
	return (res);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-9));	
	return (0);
}
*/
