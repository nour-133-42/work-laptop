/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:47:19 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
	pthread_mutex_t	meal_mutex;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			meals_required;
	int				stop;
	int				threads_created;
	int				monitor_created;
	int				forks_initialized;
	int				print_mutex_initialized;
	int				stop_mutex_initialized;
	int				meal_mutexes_initialized;
	long			start_time;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}					t_data;

int		validate_arguments(int argc, char **argv);
int		parsarguments(int argc, char **argv, t_data *data);
int		creat_mutexes(t_data *data);
int		creat_philos(t_data *data);
long	get_current_time(void);
void	usleep_smart(t_data *data, long usec);
int		simulation_stopped(t_data *data);
void	request_stop(t_data *data);
int		philo_is_full(t_data *data, int i);
void	init_meal_times(t_data *data);
void	print_action(t_philo *philo, const char *action);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
void	*philosopher_routine(void *arg);
void	*monitor_routine(void *arg);
int		create_philo_threads(t_data *data);
int		start_simulation(t_data *data);
void	cleanup(t_data *data);

#endif
