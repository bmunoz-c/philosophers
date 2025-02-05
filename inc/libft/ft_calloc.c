/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:25:19 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/01/26 17:23:19 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, count * size);
	return (tmp);
}
/*
//ALOJA ESPACIO PARA COUNT_OBJECTS QUE SON SIZE_BYTES DE MEMORIA
//RETURN POINTER DE LA POSICION DE MEMORIA
//
//
//RETURN POINTER ALLOCATED MEMORY
//RETURN 0 SI HAY ERROR
*/
