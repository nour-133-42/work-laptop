/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:05:00 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	request_stop(t_data *data)
{
	if (!data->stop_mutex_initialized)
	{
		data->stop = 1;
		return ;
	}
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}

int	philo_is_full(t_data *data, int i)
{
	int	is_full;

	if (data->meals_required == -1)
		return (0);
	pthread_mutex_lock(&data->philos[i].meal_mutex);
	is_full = (data->philos[i].meals_eaten >= data->meals_required);
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	return (is_full);
}

void	init_meal_times(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
	i = -1;
	while (++i < data->nb_philo)
		data->philos[i].last_meal = data->start_time;
}

void	usleep_smart(t_data *data, long usec)
{
	long	start;
	long	elapsed;

	start = get_current_time();
	while (1)
	{
		elapsed = get_current_time() - start;
		if (elapsed >= (usec + 999) / 1000)
			break ;
		if (simulation_stopped(data))
			break ;
		usleep(1000);
	}
}
