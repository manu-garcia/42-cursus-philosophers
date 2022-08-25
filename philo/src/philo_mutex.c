/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/25 18:39:12 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> //usleep

#include "state.h"

int	unlock_all_philo_creation_mutex(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		pthread_mutex_unlock(&state->philos[n_philo].creation_mutex);
		usleep(100);
		n_philo += 2;
	}
	n_philo = 1;
	while (n_philo < state->n_philos)
	{
		pthread_mutex_unlock(&state->philos[n_philo].creation_mutex);
		usleep(100);
		n_philo += 2;
	}
	return (1);
}

int	init_all_fork_mutex(t_state *state)
{
	int	n_philo;

	state->fork_mutex = (pthread_mutex_t *) malloc(
			state->n_philos * sizeof(pthread_mutex_t));
	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		pthread_mutex_init(&state->fork_mutex[n_philo], NULL);
		n_philo++;
	}
	return (1);
}
