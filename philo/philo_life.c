/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:05:00 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_stop(t_data *d)
{
	pthread_mutex_lock(&d->stop_mutex);
	d->stop = 1;
	pthread_mutex_unlock(&d->stop_mutex);
}

static int	check_death(t_data *d, int i)
{
	long	elapsed;

	pthread_mutex_lock(&d->philos[i].meal_mutex);
	elapsed = get_current_time() - d->philos[i].last_meal;
	pthread_mutex_unlock(&d->philos[i].meal_mutex);
	if (elapsed > d->time_die)
	{
		print_action(&d->philos[i], "died");
		set_stop(d);
		return (1);
	}
	return (0);
}

static int	all_full_stop(t_data *d, int all_full)
{
	if (d->meals_required != -1 && all_full)
	{
		set_stop(d);
		return (1);
	}
	return (0);
}

static int	philo_is_full(t_data *d, int i)
{
	int	is_full;

	if (d->meals_required == -1)
		return (0);
	pthread_mutex_lock(&d->philos[i].meal_mutex);
	is_full = (d->philos[i].meals_eaten >= d->meals_required);
	pthread_mutex_unlock(&d->philos[i].meal_mutex);
	return (is_full);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		usleep_smart(philo->data, philo->data->time_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep_smart(philo->data, philo->data->time_eat * 1000 / 2);
	while (!simulation_stopped(philo->data))
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;
	int		i;
	int		all_full;

	d = (t_data *)arg;
	while (!simulation_stopped(d))
	{
		i = -1;
		all_full = 1;
		while (++i < d->nb_philo)
		{
			if (check_death(d, i))
				return (NULL);
			if (d->meals_required != -1 && !philo_is_full(d, i))
				all_full = 0;
		}
		if (all_full_stop(d, all_full))
			return (NULL);
		usleep_smart(d, 1000);
	}
	return (NULL);
}
