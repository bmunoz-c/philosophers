/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:40:47 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/06 22:01:49 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Function Name:	philosopher_routine
 *
 *		Description:
 *
 *			This function defines the routine for each philosopher thread.
 *			Each philosopher follows a cycle of thinking, taking forks,
 *			eating,
				and sleeping while checking if the simulation is still running.
 *			If a philosopher surpasses the time_to_die without eating,
 *			the simulation ends.
 *
 *		Parameters:
 *
 *			void	*arg	-	A pointer to a t_philo struct representing
 *								the philosopher's data.
 *
 *		Return Value:
 *
 *			void * - Always returns NULL when the philosopher exits its routine.
 */

//TODO Si solo hay un filosofo, coger un fork, esperar el tiempo de muerte, morir.
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
			printf("Philosopher %d died\n", philo->id);
			philo->data->simulation_running = 0;
			pthread_mutex_unlock(&philo->data->simulation_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->simulation_mutex);
		// print_log(get_time(ms) - philo->data->start_time, philo->id, "is thinking");
		printf("%ld Philosopher %d is thinking\n", get_time_ms()
			- philo->data->start_time, philo->id);
		usleep(1000);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->r_fork);
			printf("Philosopher %d took right fork\n", philo->id);
			pthread_mutex_lock(philo->l_fork);
			printf("Philosopher %d took left fork\n", philo->id);
		}
		else
		{
			pthread_mutex_lock(philo->l_fork);
			printf("Philosopher %d took left fork\n", philo->id);
			pthread_mutex_lock(philo->r_fork);
			printf("Philosopher %d took left fork\n", philo->id);
		}
		/*
		pthread_mutex_lock(philo->l_fork);
		printf("Philosopher %d took left fork\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("Philosopher %d took right fork\n", philo->id);
		*/
		pthread_mutex_lock(philo->last_eat_mutex);
		philo->last_eat = get_time_ms();
		pthread_mutex_unlock(philo->last_eat_mutex);
		pthread_mutex_lock(philo->meals_eaten_mutex);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->meals_eaten_mutex);
		printf("Philosopher %d is eating\n", philo->id);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		printf("Philosopher %d finish eating and is sleeping\n", philo->id);
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

// TODO FUNCION PARA PRINTAR LOS MENSAJES (ms, id_philo, mensaje)
// Solo printa si data->simulation_running == 1

/*
 *		Function Name:	monitor_routine
 *
 *		Description:
 *
 *			This function defines the routine for the monitor thread.
 *			It continuously checks if any philosopher has exceeded the
 *			allowed time without eating, in which case the simulation stops.
 *			Additionally, it verifies if all philosophers have eaten the
 *			required number of meals and stops the simulation if so.
 *
 *		Parameters:
 *
 *			void	*arg	-	A pointer to a t_data struct containing
 *								the simulation data.
 *
 *		Return Value:
 *
 *			void * - Always returns NULL when the monitoring routine ends.
 */
void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		full_philos;

	data = (t_data *)arg;
	full_philos = 0;
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
				printf("Philosopher %d died\n", data->philos[i].id);
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
}

/*
 *		Function Name:	start_simulation
 *
 *		Description:
 *
 *			This function starts the philosopher simulation. It creates a
 *			thread for each philosopher and a separate monitor thread to
 *			check the simulation conditions. After execution, it waits for
 *			all threads to finish and then cleans up allocated resources.
 *
 *		Parameters:
 *
 *			t_data	*data	-	A pointer to the t_data struct containing
 *								the simulation data and philosopher information.
 *
 *		No Return Value:
 *
 */
void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].data = data;
		pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
			&data->philos[i]);
		i++;
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
/*
 //Check if any philosopher dies
void	check_if_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (get_time_ms() - data->philos[i].last_eat
			> &data->philos[i].time_to_die)
		{
			printf("Philosopher %d died\n", data->philos[i].id);
			data->simulation_running = 0;
			return ;
		}
		i++;
	}
}  */
