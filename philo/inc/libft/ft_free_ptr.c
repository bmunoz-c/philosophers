/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:21:33 by bmunoz-c          #+#    #+#             */
/*   Updated: 2025/01/17 20:30:51 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

/* 
//TODO: PROBAR ESTA FUNCION
void free_ptr(void *ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }
}
*/
