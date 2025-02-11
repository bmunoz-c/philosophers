/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:39:11 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 17:21:10 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Description:
 *			Checks if a specific philosopher has died and updates  
 *			the simulation status if necessary.
 *
 *		Returns 1 if the philosopher is dead, 0 otherwise.
*/
int	check_if_dead(t_data *data, int i)
{
	pthread_mutex_lock(data->philos[i].last_eat_mutex);
	pthread_mutex_lock(&data->simulation_mutex);
	if (!data->simulation_running)
	{
		pthread_mutex_unlock(data->philos[i].last_eat_mutex);
		pthread_mutex_unlock(&data->simulation_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->simulation_mutex);
	if (get_time_ms() - data->philos[i].last_eat > data->time_to_die)
	{
		print_log("is dead", get_time_ms(), &data->philos[i]);
		pthread_mutex_unlock(data->philos[i].last_eat_mutex);
		pthread_mutex_lock(&data->simulation_mutex);
		data->simulation_running = 0;
		pthread_mutex_unlock(&data->simulation_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->philos[i].last_eat_mutex);
	return (0);
}

/*
 *		Description:
 *			Checks if a philosopher has eaten the required meals and  
 *			increments the count of full philosophers.
 *
 *		Returns 1 if all philosophers are full, 0 otherwise.
*/
int	check_meals(t_data *data, int *full_philos, int i)
{
	pthread_mutex_lock(data->philos[i].meals_eaten_mutex);
	if (data->meals_required != -1
		&& data->philos[i].meals_eaten >= data->meals_required)
		(*full_philos)++;
	pthread_mutex_unlock(data->philos[i].meals_eaten_mutex);
	return (*full_philos == data->num_philo);
}

/*
 *		Description:
 *			Checks if any philosopher has died or if all have eaten  
 *			the required meals, updating the simulation status accordingly.
 *
 *		Returns 1 if the simulation should stop, 0 otherwise.
*/
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
 *			Monitors the simulation, checking if any philosopher has  
 *			died or if all have eaten the required meals.
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
