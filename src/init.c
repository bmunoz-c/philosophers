/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:31:03 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 16:10:13 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Description:
 *			Allocates memory for forks and initializes their mutexes.
 *
 *		Return 0 on success, 1 on failure.
*/
int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (printf("Error: malloc failed\n"), 1);
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

/*
 *		Description:
 *			Allocates memory for philosophers, initializes their  
 *			attributes, assigns forks, and sets up mutexes.
 *
 *		Return 0 on success, 1 on failure.
 */
int	init_philosophers(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (printf("Error: malloc failed\n"), 1);
	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_eat = get_time_ms();
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].meals_eaten_mutex = malloc(sizeof(pthread_mutex_t));
		data->philos[i].last_eat_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philos[i].meals_eaten_mutex, NULL);
		pthread_mutex_init(data->philos[i].last_eat_mutex, NULL);
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

/*
 *		Description:
 *			Validates input, initializes simulation parameters,  
 *			and sets up mutexes and philosophers.

 *		Return 0 on success, 1 on failure.
 */
int	init_simulation(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid number of arguments\n");
		printf("\tTry\t[./philo]\t [👤]\t[💀]\t[🍽️ ]\t[🛏️ ]\t [meals_to_eat]\n");
		return (1);
	}
	if (!valid_arguments(argc, argv))
		return (1);
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	else
		data->meals_required = -1;
	data->start_time = get_time_ms();
	data->simulation_running = 1;
	if (pthread_mutex_init(&data->simulation_mutex, NULL) != 0)
		return (printf("Error: mutex init failed\n"), 1);
	if (init_mutexes(data) || init_philosophers(data))
		return (1);
	return (0);
}
