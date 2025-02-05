/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:22:30 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/05 21:57:22 by borjamc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
    int				id;
    pthread_t       thread;
    pthread_mutex_t	*l_fork;
    pthread_mutex_t	*r_fork;
    int				meals_eaten;
    long		    last_eat;
}					t_philo;

typedef struct s_data
{
    int				num_philo;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				meals_required;
    long            start_time;
    int             simulation_running;
    pthread_mutex_t simulation_mutex;
    pthread_mutex_t	*forks;
    t_philo			*philos;
}					t_data;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

long    get_time(void);

int     init_simulation(t_data *data, int argc, char **argv);

void    start_simulation(t_data *data);

void    cleanup(t_data *data);

#endif