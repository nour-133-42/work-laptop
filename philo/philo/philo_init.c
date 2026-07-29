/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:05:00 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		data->forks_initialized++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (1);
	data->print_mutex_initialized = 1;
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (1);
	data->stop_mutex_initialized = 1;
	return (0);
}

int	creat_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_current_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
			return (1);
		data->meal_mutexes_initialized++;
	}
	return (0);
}

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	simulation_stopped(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->stop_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (stop);
}

void	print_action(t_philo *philo, const char *action)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->print_mutex);
	current_time = get_current_time() - philo->data->start_time;
	if (!simulation_stopped(philo->data))
		printf("%ld %d %s\n", current_time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
