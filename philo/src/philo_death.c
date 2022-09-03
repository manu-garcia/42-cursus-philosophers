/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 15:17:12 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // exit
#include <stdio.h> // printf

#include "state.h"
#include "stats.h"
#include "log.h"
#include "atime.h"

int	check_if_dead(t_philo *philo)
{
	long	time;

	if (philo->ntimes_must_eat
		&& philo->n_times_eaten >= philo->ntimes_must_eat)
		return (0);
	time = (get_milliseconds_now() - philo->last_time_ate);
	if (time > philo->time_to_die)
	{
		log_philo_msg(philo, "\033[1;31m died \033[0m");
		pthread_mutex_lock(philo->death_mutex);
		philo->is_dead = 1;
		printf("Took %ld ms to eat...\n", time);
		return (1);
	}
	return (0);
}

int	check_if_any_dead_or_finished(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		if (state->philos[n_philo].has_finished)
			return (1);
		if (check_if_dead(&state->philos[n_philo]))
			return (1);
		n_philo++;
	}
	return (0);
}

int	check_if_all_started(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		if (state->philos[n_philo].has_started == 0)
			return (0);
		n_philo++;
	}
	return (1);
}

int	check_if_all_finished(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		if (state->philos[n_philo].has_finished == 0)
			return (0);
		n_philo++;
	}
	return (1);
}

int	set_all_dead(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		state->philos[n_philo].is_dead = 1;
		n_philo++;
	}
	return (1);
}
