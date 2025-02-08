/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:40:47 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/08 14:07:59 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Description:
 *			This function defines the routine for each philosopher thread.
 *			Each philosopher follows a cycle of thinking, taking forks,
 *			eating, and sleeping while checking if the simulation is still running.
 *			If a philosopher surpasses the time_to_die without eating,
 *			the simulation ends.
 *
 *		Return NULL when the philosopher exits its routine.
 */

//TODO Si solo hay un filosofo,coger un fork,esperar el tiempo de muerte,morir.

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    pthread_mutex_lock(&philo->data->simulation_mutex);
    philo->last_eat = get_time_ms();
    pthread_mutex_unlock(&philo->data->simulation_mutex);
    while (1)
    {
        if (check_death(philo))
            break;

        ft_think(philo);
        ft_take_forks(philo);
        ft_eat(philo);
    	ft_sleep(philo);
    }
    return (NULL);
}

// Solo printa si data->simulation_running == 1


void handle_single_philo(t_data *data)
{
	print_log("has taken a fork", get_time_ms(), &data->philos[0]);
	//printf("Philosopher 1 has taken a fork\n");
	usleep(data->time_to_die * 1000);
	print_log("is dead", get_time_ms(), &data->philos[0]);
	//printf("Philosopher 1 is dead\n");
}

/*
 *		Description:
 *			This function starts the philosopher simulation. It creates a
 *			thread for each philosopher and a separate monitor thread to
 *			check the simulation conditions. After execution, it waits for
 *			all threads to finish and then cleans up allocated resources.
 */
void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	if (data->num_philo == 1)
	{
		handle_single_philo(data);
		cleanup(data);
		return ;
	}
	while (++i < data->num_philo)
	{
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
			&data->philos[i]);
	}
	pthread_create(&monitor, NULL, monitor_routine, data);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	cleanup(data);
}
