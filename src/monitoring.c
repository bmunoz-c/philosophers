/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:39:11 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/08 14:07:33 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_if_dead(t_data *data, int i)
{
	pthread_mutex_lock(data->philos[i].last_eat_mutex);
	if (get_time_ms() - data->philos[i].last_eat > data->time_to_die)
	{
		pthread_mutex_unlock(data->philos[i].last_eat_mutex);
		print_log("is dead", get_time_ms(), &data->philos[i]);
		pthread_mutex_lock(&data->simulation_mutex);
		data->simulation_running = 0;
		pthread_mutex_unlock(&data->simulation_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->philos[i].last_eat_mutex);
	return (0);
}

int check_meals(t_data *data, int *full_philos, int i)
{
	pthread_mutex_lock(data->philos[i].meals_eaten_mutex);
	if (data->meals_required != -1
		&& data->philos[i].meals_eaten >= data->meals_required)
		(*full_philos)++;
	pthread_mutex_unlock(data->philos[i].meals_eaten_mutex);
	return (*full_philos == data->num_philo);
}

int	check_philosophers(t_data *data)
{
	int	i;
	int	full_philos;

	full_philos = 0;
	i = 0;
	while (i < data->num_philo)
	{
		if (check_if_dead(data, i))
			return (1);
		if (check_meals(data, &full_philos, i))
		{
			printf("All philosophers have eaten %d meals\n",
				data->meals_required);
			pthread_mutex_lock(&data->simulation_mutex);
			data->simulation_running = 0;
			pthread_mutex_unlock(&data->simulation_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}
/*
 *		Description:
 *			This function defines the routine for the monitor thread.
 *			It continuously checks if any philosopher has exceeded the
 *			allowed time without eating, in which case the simulation stops.
 *			Additionally, it verifies if all philosophers have eaten the
 *			required number of meals and stops the simulation if so.
 *
 *		Return NULL when the monitoring routine ends.
 */
 void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->simulation_mutex);
		if (!data->simulation_running)
		{
			pthread_mutex_unlock(&data->simulation_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->simulation_mutex);
		if (check_philosophers(data))
			return (NULL);
		usleep(5000);
	}
	return (NULL);
} 
