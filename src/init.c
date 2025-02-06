/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:31:03 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/06 21:44:50 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Function Name:	init_mutexes
 *
 *		Description:
 *
 *			This function initializes the mutexes for the philosophers' forks.
 *			It allocates memory for the required number of mutexes and
 *			initializes each one.
 *
 *		Parameters:
 *
 *			t_data	*data	-	The pointer to the t_data struct containing
 *								the number of philosophers and execution data.
 *
 *		Return Value:
 *
 *			int - Returns 0 if all mutexes are initialized successfully.
 *					Returns 1 if memory allocation fails or a mutex
 *					initialization fails.
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
 *		Function Name:	init_philosophers
 *
 *		Description:
 *
 *			This function initializes the philosophers' data structures.
 *			It allocates memory for the philosophers and sets their
 *			initial attributes, including ID, meal count, last meal time,
 *			and assigned forks.
 *
 *		Parameters:
 *
 *			t_data	*data	-	The pointer to the t_data struct containing
 *								the number of philosophers and execution data.
 *
 *		Return Value:
 *
 *			int - Returns 0 if all philosophers are initialized successfully.
 *					Returns 1 if memory allocation fails.
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
	/*if (data->num_philo == 1)
		data->philos[0].l_fork = NULL;*/
	return (0);
}

/*
 *		Function Name:	init_simulation
 *
 *		Description:
 *
 *			This function initializes the simulation by validating the input
 *			arguments, setting up the simulation parameters, and initializing
 *			the necessary mutexes and philosopher structures.
 *
 *		Parameters:
 *
 *			t_data	*data	-	The pointer to the t_data struct where
 *								the simulation data will be stored.
 *			int		argc	-	The number of command-line arguments.
 *			char	**argv	-	The array of argument strings.
 *
 *		Return Value:
 *
 *			int - Returns 0 if the simulation is initialized successfully.
 *					Returns 1 if there is an error in argument validation,
 *					memory allocation, or mutex initialization.
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
