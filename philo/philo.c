/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:46:29 by nalshmai          #+#    #+#             */
/*   Updated: 2026/06/18 18:00:42 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsarguments(int argc, char **argv, t_data *data)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	else
		data->meals_required = -1; // No meal limit
	if (data->nb_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0)
	{
		printf("Error: Invalid argument values.\n");
		return (1);
	}
	return (0);
}

int	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error: Arguments must be positive integers.\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	creat_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error: Failed to initialize mutex.\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		printf("Error: Failed to initialize print mutex.\n");
		return (1);
	}
	return (0);
}

int	creat_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philos[i].data = data;
		i++;
	}
	return (0);
}
pthread_mutex_t	*get_fork(t_philo *philo, int fork_index)
{
	if (fork_index == 0)
		return (philo->left_fork);
	else if (fork_index == 1)
		return (philo->right_fork);
	else
		return (NULL);
}

int	pthread_mutex_lock_safe(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf("Error: Failed to lock mutex.\n");
		return (1);
	}
	return (0);
}

int	pthread_mutex_unlock_safe(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf("Error: Failed to unlock mutex.\n");
		return (1);
	}
	return (0);
}

int	simulation_stopped(t_data *data)
{
	int	stop;

	if (pthread_mutex_lock_safe(&data->print_mutex) != 0)
		return (1);
	stop = data->stop;
	if (pthread_mutex_unlock_safe(&data->print_mutex) != 0)
		return (1);
	return (stop);
}

void	print_action(t_philo *philo, const char *action)
{
	long	current_time;

	if (pthread_mutex_lock_safe(&philo->data->print_mutex) != 0)
		return ;
	current_time = get_current_time();
	printf("%ld %d %s\n", current_time, philo->id, action);
	if (pthread_mutex_unlock_safe(&philo->data->print_mutex) != 0)
		return ;
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}
void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
void	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_action(philo, "is done eating");
	usleep(philo->data->time_eat * 1000);
}
void	sleep_philo(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_sleep * 1000);
}
void	think(t_philo *philo)
{
	print_action(philo, "is thinking");
}
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		usleep(philo->data->time_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
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
start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
void	*cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->philos);
}
int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	if (validate_arguments(argc, argv) != 0)
		return (1);
	if (parsarguments(argc, argv, &data) != 0)
		return (1);
	if (creat_mutexes(&data) != 0)
		return (1);
	if (creat_philos(&data) != 0)
		return (1);
	if (start_simulation(&data) != 0)
		return (1);
	cleanup(&data);
	// // if (pthread_mutex_init(&data.print_mutex, NULL) != 0)
	// // 	return (1);
	// // if (pthread_mutex_lock_safe(&data.print_mutex) != 0)
	// // 	return (1);
	// // if (pthread_mutex_unlock(&data.print_mutex) != 0)
	// // 	return (1);
	// while (1)
	// {
	// 	if (data.stop)
	// 		break ;
	// 	if (pthread_mutex_lock_safe(&data.print_mutex) != 0)
	// 		return (1);
	// 	if (pthread_mutex_unlock(&data.print_mutex) != 0)
	// 		return (1);
	//     if()
	// 	// Simulation logic for philosophers goes here
	// 	// For example,
	// 	// you can create threads for each philosopher and manage their actions
	// 	// This is just a placeholder for the actual implementation
	// 	break ; // Remove this line when implementing the simulation
	// }
	return (0);
}
