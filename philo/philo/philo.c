/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:46:29 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:00 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsarguments(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	else
		data->meals_required = -1;
	if (data->nb_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0)
	{
		printf("Error: Invalid argument values.\n");
		return (1);
	}
	return (0);
}

void	cleanup(t_data *data)
{
	int	i;

	if (data->monitor_created)
		pthread_join(data->monitor, NULL);
	i = -1;
	while (++i < data->threads_created)
		pthread_join(data->philos[i].thread, NULL);
	i = -1;
	while (++i < data->forks_initialized)
		pthread_mutex_destroy(&data->forks[i]);
	i = -1;
	while (++i < data->meal_mutexes_initialized)
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
	if (data->print_mutex_initialized)
		pthread_mutex_destroy(&data->print_mutex);
	if (data->stop_mutex_initialized)
		pthread_mutex_destroy(&data->stop_mutex);
	free(data->forks);
	free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (validate_arguments(argc, argv) != 0)
		return (1);
	if (parsarguments(argc, argv, &data) != 0)
		return (1);
	if (creat_mutexes(&data) != 0)
	{
		cleanup(&data);
		return (1);
	}
	if (creat_philos(&data) != 0)
	{
		cleanup(&data);
		return (1);
	}
	if (start_simulation(&data) != 0)
	{
		cleanup(&data);
		return (1);
	}
	cleanup(&data);
	return (0);
}
