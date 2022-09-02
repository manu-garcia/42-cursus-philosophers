/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/09/02 13:53:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> //usleep
#include <string.h>

#include "state.h"
#include "log.h"

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

	state->fork_mutex = (t_fork *) malloc(
			state->n_philos * sizeof(t_fork));
	memset(state->fork_mutex, 0, state->n_philos * sizeof(t_fork));
	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		pthread_mutex_init(&(state->fork_mutex[n_philo].mutex), NULL);
		n_philo++;
	}
	return (1);
}

void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->taken = 1;
	log_philo_msg(philo, "has taken a fork");
}

void	leave_fork(t_fork *fork)
{
	fork->taken = 0;
	pthread_mutex_unlock(&fork->mutex);
}
