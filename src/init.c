/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:31:03 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/06 00:23:55 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//Devuelve el tiempo actual en milisegundos
long    get_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

//Inicializa un mutex por cada tenedor
int init_mutexes(t_data *data)
{
    int i;

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

//Asigna IDs a los filosofos y les da referencias a sus tenedores
int init_philosophers(t_data *data)
{
    int i;

    data->philos = malloc(sizeof(t_philo) * data->num_philo);
    if (!data->philos)
        return (printf("Error: malloc failed\n"), 1);
    i = 0;
    while (i < data->num_philo)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_eat = get_time();
        data->philos[i].l_fork = &data->forks[i];
        data->philos[i].r_fork = &data->forks[(i + 1) % data->num_philo];
        data->philos[i].data = data;
        i++;
    }
    return (0);
}

int valid_arguments(int argc, char **argv)
{
    int i;
    int num;
    
    i = 1;
    while (i < argc)
    {
       num = ft_atoi(argv[i]);
       if (num <= 0)
       {
            printf("Error: Argument %d (%s) must be a positive number\n", i, argv[i]);
            return (0);
       }
        i++;
    }
    return (1);
}

//Toma argumentos del programa, guarda la configuracion y llama a las funciones de inicializacion
int init_simulation(t_data *data, int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        printf("Error: invalid number of arguments\n \tTry ~ ./philo +X X X X ~\n");
        return ( 1);
    }
    if (!valid_arguments(argc, argv))
        return (1);
    data->num_philo = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->meals_required = (argc == 6) ? ft_atoi(argv[5]) : -1;
    data->start_time = get_time();
    data->simulation_running = 1;
    if (pthread_mutex_init(&data->simulation_mutex, NULL) != 0)
        return (printf("Error: mutex init failed\n"), 1);
  /*   if (data->num_philo < 2 || data->time_to_die < 60 || data->time_to_eat < 60
        || data->time_to_sleep < 60 || (argc == 6 && data->must_eat_count < 1))
        return (printf("Error: invalid arguments\n"), 1); */
    if (init_mutexes(data) || init_philosophers(data))
        return (1);
    return (0);
}
