/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:53:52 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/29 16:53:52 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread.\n");
			request_stop(data);
			return (1);
		}
		data->threads_created++;
		i++;
	}
	return (0);
}

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
	i = -1;
	while (++i < data->nb_philo)
		data->philos[i].last_meal = data->start_time;
	if (create_philo_threads(data) != 0)
		return (1);
	if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
	{
		printf("Error: Failed to create monitor thread.\n");
		request_stop(data);
		return (1);
	}
	data->monitor_created = 1;
	return (0);
}
