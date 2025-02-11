/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:11:44 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/11 17:09:30 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//think action
void	ft_think(t_philo *philo)
{
	philo->act_time = get_time_ms() - philo->data->start_time;
	print_log("is thinking", philo->act_time, philo);
	usleep(1000);
}

//take forks action
void	ft_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_log("has taken a fork", get_time_ms(), philo);
		pthread_mutex_lock(philo->l_fork);
		print_log("has taken a fork", get_time_ms(), philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_log("has taken a fork", get_time_ms(), philo);
		pthread_mutex_lock(philo->r_fork);
		print_log("has taken a fork", get_time_ms(), philo);
	}
}

//eat action
void	ft_eat(t_philo *philo)
{
	if (check_philo_meals(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	update_last_eat(philo);
	update_meals_eaten(philo);
	print_log("is eating", philo->act_time, philo);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

//sleep action
void	ft_sleep(t_philo *philo)
{
	philo->act_time = get_time_ms();
	print_log("is sleeping", philo->act_time, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
