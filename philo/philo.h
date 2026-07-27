/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:47:19 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/22 16:48:59 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// typedef struct s_philo	t_philo;
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
	long			start_time;

	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;

	t_philo			*philos;
}					t_data;

int					ft_atoi(const char *nptr);

#endif