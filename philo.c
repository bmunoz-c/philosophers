/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:40:47 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/05 22:25:26 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    - Cadafilosofo entra en un bucle infinito.
    - Toma sus dos tenedores (bloqueando los mutex).
    - Simula el acto de comer (usleep).
    - Suelta los tenedores (desbloqueando los mutex).
    - Duerme y repite ciclo.
*/
void    *philosopher_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        pthread_mutex_lock(philo->data->simulation_mutex);
        if (!philo->data->simulation_running)
        {
            pthread_mutex_unlock(philo->data->simulation_mutex);
            break ;
        }
        pthread_mutex_unlock(philo->data->simulation_mutex);
        printf("Philosopher %d is thinking\n", philo->id);
        pthread_mutex_lock(philo->l_fork);
        printf("Philosopher %d took left fork\n", philo->id);
        pthread_mutex_lock(philo->r_fork);
        printf("Philosopher %d took right fork\n", philo->id);
        printf("Philosopher %d is eating\n", philo->id);
        philo->last_eat = get_time();
        philo->meals_eaten++;
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(philo->r_fork);
        pthread_mutex_unlock(philo->l_fork);
        printf("Philosopher %d finish eating and is sleeping\n", philo->id);
        usleep(philo->data->time_to_sleep * 1000);
    }
    return (NULL);
}

/*
    - Revisa constantemente si algun filosofo ha superado time_to_die sin comer.
    - Si el filosofo muere, termina el programa con un exit.
*/
void    *monitor_routine(void *arg)
{
    t_data *data;
    int i;
    int full_philos;

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
            if (get_time() - data->philos[i].last_eat > data->time_to_die)
            {
                printf("Philosopher %d died\n", data->philos[i].id);
                pthread_mutex_lock(&data->simulation_mutex);
                data->simulation_running = 0;
                pthread_mutex_unlock(&data->simulation_mutex);
                return (NULL);
            }
            if (data->meals_required != -1 && data->philos[i].meals_eaten >= data->meals_required)
                full_philos++;
            i++;
        }
        if (data->meals_required != -1 && full_philos == data->num_philo)
        {
            printf("All philosophers have eaten %d meals\n", data->meals_required);
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
    - Crea un hilo por cada filosofo.
    - Espera a que todos los hilos terminen (pthread_join()).
    - Crea un hilo (monitor_routine) para vigilar si alguien muere.
*/
void    start_simulation(t_data *data)
{
    int i;
    pthread_t   monitor;

    i = 0;
    while (i < data->num_philo)
    {
        data->philos[i].data = data;
        pthread_create(&data->philos[i].thread, NULL, philosopher_routine, &data->philos[i]);
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