/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:22:30 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/06 22:02:50 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libft/libft.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				meals_eaten;
	pthread_mutex_t	*meals_eaten_mutex;
	pthread_mutex_t	*last_eat_mutex;
	long			last_eat;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	long			start_time;
	int				simulation_running;
	pthread_mutex_t	simulation_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

long				get_time_ms(void);

int					valid_arguments(int argc, char **argv);

void				start_simulation(t_data *data);

void				cleanup(t_data *data);

int					init_simulation(t_data *data, int argc, char **argv);

#endif
