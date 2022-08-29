/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/29 20:19:38 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#include "state.h"
#include "error.h"
#include "philo_thread.h"
#include "philo_mutex.h"

int	create_philo(t_state *state, int n_philo)
{
	t_philo	*philo;

	philo = &state->philos[n_philo];
	philo->state = state;
	philo->time_to_die = state->time_to_die;
	philo->time_to_eat = state->time_to_eat;
	philo->time_to_sleep = state->time_to_sleep;
	philo->n_philo = n_philo;
	philo->n_forks = state->n_philos;
	philo->ntimes_must_eat = state->ntimes_must_eat;
	if (n_philo == 0)
		philo->fork_left = &state->fork_mutex[state->n_philos - 1];
	else
		philo->fork_left = &state->fork_mutex[n_philo - 1];
	philo->fork_right = &state->fork_mutex[n_philo];
	philo->fork_taking_mutex = &state->fork_taking_mutex;
	pthread_mutex_init(&philo->creation_mutex, NULL);
	pthread_mutex_lock(&philo->creation_mutex);
	pthread_mutex_init(&philo->death_mutex, NULL);
	if (pthread_create(&philo->thread, NULL, &philo_thread, philo) != 0)
		return (exit_with_error("Error creating thread.\n", state));
	return (1);
}

int	create_all_philos(t_state *state)
{
	int	n_philo;

	pthread_mutex_init(&state->fork_taking_mutex, NULL);
	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		create_philo(state, n_philo);
		n_philo++;
	}
	unlock_all_philo_creation_mutex(state);
	return (1);
}

int	wait_for_all_philos(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		if (pthread_join(state->philos[n_philo].thread, NULL) != 0)
			return (exit_with_error("Error joining thread.\n", state));
		n_philo++;
	}
	return (1);
}
