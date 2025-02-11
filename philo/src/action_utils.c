/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:37 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 17:31:54 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 *		Description:
 *			Updates the philosopher's last meal time safely using a mutex.
*/
void	update_last_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->act_time = get_time_ms();
	philo->last_eat = philo->act_time;
	pthread_mutex_unlock(philo->last_eat_mutex);
}

/*
 *		Description:
 *			Increments the philosopher's meal count safely using a mutex.
*/
void	update_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(philo->meals_eaten_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meals_eaten_mutex);
}

int	check_philo_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->meals_eaten_mutex);
	if (philo->data->meals_required != -1
		&& philo->meals_eaten >= philo->data->meals_required)
	{
		pthread_mutex_unlock(philo->meals_eaten_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->meals_eaten_mutex);
	return (0);
}
