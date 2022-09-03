/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 15:26:00 by manugarc         ###   ########.fr       */
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
	n_philo = -1;
	while (++n_philo < state->n_philos)
	{
		if (state->philos[n_philo].n_times_eaten
			< state->stats.n_avg_meals_eaten)
			printf("\033[1;31m");
		printf("n_philo %d ate(%d), avg(%.2f), min(%d), max(%d)",
			n_philo + 1,
			state->philos[n_philo].n_times_eaten,
			state->stats.n_avg_meals_eaten,
			state->stats.n_min_meals_eaten,
			state->stats.n_max_meals_eaten);
		printf("greedy(%d), fleft(%d), fright(%d)\033[0m\n",
			state->philos[n_philo].greedy_penalty,
			state->philos[n_philo].fork_left->taken,
			state->philos[n_philo].fork_right->taken);
	}
	printf("%d philos have eaten.\n", state->stats.n_philos_eaten);
	printf("%d philos have NOT eaten.\n", state->stats.n_philos_not_eaten);
	printf("%d meals have been eaten.\n", state->stats.n_meals_eaten);
	printf("%d is max times eaten.\n", state->stats.n_max_meals_eaten);
}

void	measure_lag(t_state *state)
{
	int		ntimes;
	int		i;
	long	end_time;
	int		diff;
	long	ms;

	ms = 100;
	ntimes = 100;
	i = -1;
	state->simulation_start_time = get_milliseconds_now();
	log_msg(state, "Before...");
	custom_sleep(ms, NULL);
	log_msg(state, "After.");
	state->simulation_start_time = get_milliseconds_now();
	while (++i < ntimes)
		custom_sleep(ms, NULL);
	end_time = get_milliseconds_now();
	diff = end_time - state->simulation_start_time;
	printf("Number times executed (%d)\n", ntimes);
	printf("Number ms to wait each time (%ld)\n", ms);
	printf("Expected ms spent (%ldms)\n", ms * ntimes);
	printf("Real ms spent (%dms)\n", diff);
	printf("Average lagged ms (%dms), when %ld expected\n", diff / ntimes, ms);
}
