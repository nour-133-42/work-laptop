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
