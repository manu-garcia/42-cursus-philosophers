/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/09/02 13:47:40 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "state.h"
#include "error.h"
#include "atime.h"
#include "log.h"
#include "philo_thread.h"
#include "philo_mutex.h"
#include "philo_death.h"

void	calc_stats(t_state	*state)
{
	int		n_philo;
	t_philo	*philo;

	memset(&state->stats, 0, sizeof(t_stats));
	state->stats.n_max_meals_eaten = 0;
	state->stats.n_min_meals_eaten = INT_MAX;
	state->stats.n_philos = state->n_philos;
	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		philo = &state->philos[n_philo];
		if (philo->n_times_eaten > 0)
			state->stats.n_philos_eaten++;
		state->stats.n_meals_eaten += philo->n_times_eaten;
		if (state->stats.n_max_meals_eaten < philo->n_times_eaten)
			state->stats.n_max_meals_eaten = philo->n_times_eaten;
		if (state->stats.n_min_meals_eaten > philo->n_times_eaten)
			state->stats.n_min_meals_eaten = philo->n_times_eaten;
		n_philo++;
	}
	state->stats.n_philos_not_eaten = state->stats.n_philos
		- state->stats.n_philos_eaten;
	state->stats.n_avg_meals_eaten = (double)state->stats.n_meals_eaten
		/ (double)state->stats.n_philos;
}

void	show_stats(t_state	*state)
{
	int	n_philo;

	calc_stats(state);
	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		if (state->philos[n_philo].n_times_eaten
			< state->stats.n_avg_meals_eaten)
			printf("\033[1;31m");
		printf("n_philo %d ate(%d), avg(%.2f), min(%d), max(%d), greedy(%d), fleft(%d), fright(%d).\033[0m\n",
			n_philo + 1,
			state->philos[n_philo].n_times_eaten,
			state->stats.n_avg_meals_eaten,
			state->stats.n_min_meals_eaten,
			state->stats.n_max_meals_eaten,
			state->philos[n_philo].greedy_penalty,
			state->philos[n_philo].fork_left->taken,
			state->philos[n_philo].fork_right->taken
			);
		n_philo++;
	}
	printf("%d philos have eaten.\n", state->stats.n_philos_eaten);
	printf("%d philos have NOT eaten.\n", state->stats.n_philos_not_eaten);
	printf("%d meals have been eaten.\n", state->stats.n_meals_eaten);
	printf("%d is max times eaten.\n", state->stats.n_max_meals_eaten);
}
