/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borjamc <borjamc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:22:30 by borjamc           #+#    #+#             */
/*   Updated: 2025/02/08 14:22:53 by borjamc          ###   ########.fr       */
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
	long			act_time;
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

//_____Utils_____//
long				get_time_ms(void);
int					valid_arguments(int argc, char **argv);
int					ft_strncmp_ph(const char *s1, const char *s2);
void 				print_log(char *action_txt, long action_time, t_philo *philo);
void				cleanup(t_data *data);

//_____Init_____//
int					init_mutexes(t_data *data);
int					init_philosophers(t_data *data);
int					init_simulation(t_data *data, int argc, char **argv);

//_____Monitoring_____//
int					check_if_dead(t_data *data, int i);
int					check_meals(t_data *data, int *full_philos, int i);
int					check_philosophers(t_data *data);
void				*monitor_routine(void *arg);

//_____Philo Action_____//
void				ft_think(t_philo *philo);
void				ft_take_forks(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);

//_____Action Utils_____//
void				update_last_eat(t_philo *philo);
void				update_meals_eaten(t_philo *philo);
int					check_death(t_philo *philo);

//_____Philosopher_____//
void				*philosopher_routine(void *arg);
void				handle_single_philo(t_data *data);
void				start_simulation(t_data *data);



#endif
