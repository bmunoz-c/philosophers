/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:11:44 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/08 13:55:41 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void ft_think(t_philo *philo)
{
    philo->act_time = get_time_ms() - philo->data->start_time;
    print_log("is thinking", philo->act_time, philo);
    usleep(1000);
}
void ft_take_forks(t_philo *philo)
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

void ft_eat(t_philo *philo)
{
    update_last_eat(philo);
    update_meals_eaten(philo);
    print_log("is eating", philo->act_time, philo);
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void ft_sleep(t_philo *philo)
{
    philo->act_time = get_time_ms();
    print_log("is sleeping", philo->act_time, philo);
    usleep(philo->data->time_to_sleep * 1000);
}