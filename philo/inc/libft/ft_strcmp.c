/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:06:00 by bmunoz-c          #+#    #+#             */
/*   Updated: 2025/01/13 22:51:48 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *ehe, char *cmp)
{
	int	i;

	i = 0;
	while (ehe[i] && cmp[i])
	{
		if (ehe[i] != cmp[i])
			return (ehe[i] - cmp[i]);
		i++;
	}
	if ((ehe[i] && !cmp[i]) || (cmp[i] && !ehe[i]))
		return (ehe[i] - cmp[i]);
	return (0);
}
