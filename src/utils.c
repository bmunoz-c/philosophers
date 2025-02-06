/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:13:44 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/06 21:49:12 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 *		Function Name:	get_time
 *
 *		Description:
 *
 *			This function retrieves the current time in milliseconds.
 *
 *		Return Value:
 *
 *			long - Returns the current time in milliseconds since the epoch.
 */
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*
 *		Function Name:	valid_arguments
 *
 *		Description:
 *
 *			This function checks if the command-line arguments provided
 *			are valid. It ensures that each argument is a positive number.
 *
 *		Parameters:
 *
 *			int		argc	-	The number of command-line arguments.
 *			char	**argv	-	The array of argument strings.
 *
 *		Return Value:
 *
 *			int - Returns 1 if all arguments are valid positive numbers.
 *					Returns 0 if any argument is invalid.
 */
int	valid_arguments(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num <= 0)
		{
			printf("Error: Argument %d (%s) must be a positive number\n", i,
				argv[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 *		Function Name:	cleanup
 *
 *		Description:
 *
 *			This function frees allocated memory and destroys mutexes
 *			to properly clean up resources at the end of the simulation.
 *
 *		Parameters:
 *
 *			t_data	*data	-	The pointer to the t_data struct containing
 *								the simulation data and allocated resources.
 *
 *		No Return Value:
 *
 */
void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(data->philos[i].meals_eaten_mutex);
		pthread_mutex_destroy(data->philos[i].last_eat_mutex);
		free(data->philos[i].meals_eaten_mutex);
		free(data->philos[i].last_eat_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->simulation_mutex);
	free(data->forks);
	free(data->philos);
}
