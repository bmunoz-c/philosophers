/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:13:44 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/05 22:14:04 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    cleanup(t_data *data)
{
    int i;

    i = 0;
    while (i < data->num_philo)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->simulation_mutex);
    free(data->forks);
    free(data->philos);
}