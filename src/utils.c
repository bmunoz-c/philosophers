/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:13:44 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 16:21:16 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//This function retrieves the current time in milliseconds.
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/*
 *		Description:
 *			This function checks if the command-line arguments provided
 *			are valid. It ensures that each argument is a positive number.
 *
 *		Returns 1 if all arguments are valid positive numbers.
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

int	ft_strncmp_ph(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (c1[i] - c2[i]);
}

/*
 *		Description:
 *			This function prints the action of a philosopher with the
 *			current time and philosopher id.
 *
 *		//TODO Solo printa si data->simulation_running == 1
*/
void	print_log(char *action_txt, long action_time, t_philo *philo)
{
	int	dead;

	action_time = get_time_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->simulation_mutex);
	dead = !philo->data->simulation_running;
	if (!dead || !ft_strncmp_ph(action_txt, "is dead"))
		printf("%ld Philosopher %d %s\n", action_time, philo->id, action_txt);
	pthread_mutex_unlock(&philo->data->simulation_mutex);
}

/*
 *		Description:
 *
 *			This function frees allocated memory and destroys mutexes
 *			to properly clean up resources at the end of the simulation.
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
