/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:46:29 by nalshmai          #+#    #+#             */
/*   Updated: 2026/07/27 18:04:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long			get_current_time(void);
int			simulation_stopped(t_data *data);

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
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
	{
		printf("Error: Failed to initialize stop mutex.\n");
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
		data->philos[i].last_meal = get_current_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].meal_mutex, NULL);
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

	if (pthread_mutex_lock_safe(&data->stop_mutex) != 0)
		return (1);
	stop = data->stop;
	if (pthread_mutex_unlock_safe(&data->stop_mutex) != 0)
		return (1);
	return (stop);
}

void	print_action(t_philo *philo, const char *action)
{
	long	current_time;

	if (pthread_mutex_lock_safe(&philo->data->print_mutex) != 0)
		return ;
	current_time = get_current_time() - philo->data->start_time;
	if (!simulation_stopped(philo->data))
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
	usleep_smart(philo->data, philo->data->time_eat * 1000);
}
void	sleep_philo(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep_smart(philo->data, philo->data->time_sleep * 1000);
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
		usleep_smart(philo->data, philo->data->time_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep_smart(philo->data, 1000);
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

long	get_current_time(void)
{
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;
	int		i;
	int		all_full;
	long	elapsed;

	d = (t_data *)arg;
	while (!simulation_stopped(d))
	{
		i = 0;
		all_full = 1;
		while (i < d->nb_philo)
		{
			pthread_mutex_lock(&d->philos[i].meal_mutex);
			elapsed = get_current_time() - d->philos[i].last_meal;
			if (elapsed > d->time_die)
			{
				pthread_mutex_unlock(&d->philos[i].meal_mutex);
				print_action(&d->philos[i], "died");
				pthread_mutex_lock(&d->stop_mutex);
				d->stop = 1;
				pthread_mutex_unlock(&d->stop_mutex);
				return (NULL);
			}
			if (d->meals_required != -1
				&& d->philos[i].meals_eaten < d->meals_required)
			{
				all_full = 0;
			}
			pthread_mutex_unlock(&d->philos[i].meal_mutex);
			i++;
		}
		// if (all_full)
		// {
		// 	print_action(&d->philos[i], "died");
		// }
		if (d->meals_required != -1 && all_full)
		{
			pthread_mutex_lock(&d->stop_mutex);
			d->stop = 1;
			pthread_mutex_unlock(&d->stop_mutex);
			return (NULL);
		}
		usleep_smart(d, 1000);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int	i;

	data->start_time = get_current_time();
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
	if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
	{
		printf("Error: Failed to create monitor thread.\n");
		return (1);
	}
	return (0);
}
void	cleanup(t_data *data)
{
	int	i;

	pthread_join(data->monitor, NULL);
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
	pthread_mutex_destroy(&data->stop_mutex);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].meal_mutex);
		i++;
	}
	free(data->forks);
	free(data->philos);
}
int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
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
	return (0);
}
