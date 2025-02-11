/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:40:47 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 16:19:58 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Description:
 *			Executes the philosopher's routine, including thinking,  
 *			taking forks, eating, and sleeping, while checking for death.
 *
 *		Return NULL when the philosopher exits its routine.
*/
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->simulation_mutex);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->data->simulation_mutex);
	while (1)
	{
		if (check_death(philo))
			break ;
		ft_think(philo);
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}

/*
 *		Description:
 *			Handles the routine for a single philosopher, including  
 *			taking a fork and dying after the time to die.
*/
void	handle_single_philo(t_data *data)
{
	print_log("has taken a fork", get_time_ms(), &data->philos[0]);
	usleep(data->time_to_die * 1000);
	print_log("is dead", get_time_ms(), &data->philos[0]);
}

/*
 *		Description:
 *			Starts the simulation by creating philosopher threads  
 *			and a monitor thread, then waits for all threads to finish.
 *			After execution, it waits for all threads to finish and 
 *			then cleans up allocated resources.
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
