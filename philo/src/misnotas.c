/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misnotas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:43:16 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/08 15:04:55 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
/*
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->simulation_mutex);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->data->simulation_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->data->simulation_mutex);
		if (!philo->data->simulation_running)
		{
			pthread_mutex_unlock(&philo->data->simulation_mutex);
			break ;
		}
		if (get_time_ms() - philo->last_eat > philo->data->time_to_die)
		{
            print_log("has taken a fork", get_time_ms(), philo);
			//printf("Philosopher %d died\n", philo->id);
			philo->data->simulation_running = 0;
			pthread_mutex_unlock(&philo->data->simulation_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->simulation_mutex);
		// print_log(get_time(ms) - philo->data->start_time, philo->id, 
			"is thinking");
        philo->act_time = get_time_ms() - philo->data->start_time;
		print_log("is thinking", philo->act_time, philo);
		//printf("%ld Philosopher %d is thinking\n",
			get_time_ms() - philo->data->start_time, philo->id);
		usleep(1000);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->r_fork);
            print_log("has taken a fork", philo->act_time, philo);
		//	printf("Philosopher %d took right fork\n", philo->id);
			pthread_mutex_lock(philo->l_fork);
            print_log("has taken a fork", philo->act_time, philo);
			//printf("Philosopher %d took left fork\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->l_fork);
            print_log("has taken a fork", get_time_ms(), philo);
			//printf("Philosopher %d took left fork\n", philo->id);
			pthread_mutex_lock(philo->r_fork);
            print_log("has taken a fork", get_time_ms(), philo);
			//printf("Philosopher %d took left fork\n", philo->id);
		}
		pthread_mutex_lock(philo->last_eat_mutex);
		philo->last_eat = get_time_ms();
		pthread_mutex_unlock(philo->last_eat_mutex);
		pthread_mutex_lock(philo->meals_eaten_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->meals_eaten_mutex);
        print_log("is eating", philo->last_eat, philo);
		//printf("Philosopher %d is eating\n", philo->id);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		philo->act_time = get_time_ms();
        print_log("is sleeping", philo->act_time, philo);
		//printf("Philosopher %d finish eating and is sleeping\n", philo->id);
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		full_philos;
   // long    action_time;

	data = (t_data *)arg;
	full_philos = 0;
   // action_time = get_time_ms() - data->start_time;
	while (1)
	{
		pthread_mutex_lock(&data->simulation_mutex);
		if (!data->simulation_running)
		{
			pthread_mutex_unlock(&data->simulation_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->simulation_mutex);
		full_philos = 0;
		i = 0;
		while (i < data->num_philo)
		{
			pthread_mutex_lock(data->philos[i].last_eat_mutex);
			if (get_time_ms() - data->philos[i].last_eat > data->time_to_die)
			{
				pthread_mutex_unlock(data->philos[i].last_eat_mutex);
				print_log("is dead", get_time_ms(), &data->philos[i]);
				//printf("Philosopher %d is dead\n", data->philos[i].id);
				pthread_mutex_lock(&data->simulation_mutex);
				data->simulation_running = 0;
				pthread_mutex_unlock(&data->simulation_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(data->philos[i].last_eat_mutex);
			pthread_mutex_lock(data->philos[i].meals_eaten_mutex);
			if (data->meals_required != -1
				&& data->philos[i].meals_eaten >= data->meals_required)
				full_philos++;
			pthread_mutex_unlock(data->philos[i].meals_eaten_mutex);
			i++;
		}
		if (data->meals_required != -1 && full_philos == data->num_philo)
		{
			printf("All philosophers have eaten %d meals\n",
				data->meals_required);
			pthread_mutex_lock(&data->simulation_mutex);
			data->simulation_running = 0;
			pthread_mutex_unlock(&data->simulation_mutex);
			return (NULL);
		}
		usleep(5000);
	}
	return (NULL);
}*/