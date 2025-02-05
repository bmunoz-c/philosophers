/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:34:59 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/05 23:35:34 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int argc, char **argv)
{
    t_data  data;

    if (init_simulation(&data, argc, argv) != 0)
        return (1);
    start_simulation(&data);
   // cleanup(&data);
    return (0);
}