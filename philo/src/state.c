/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:30 by manu              #+#    #+#             */
/*   Updated: 2022/08/22 18:52:43 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "state.h"
#include "error.h"
#include "ft_atoi.h"

static int	init_state_parameters(t_state *state, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (exit_with_error("Error. Invalid arguments\n", state));
	state->n_philos = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->ntimes_must_eat = ft_atoi(argv[5]);
	return (1);
}

int	init_state(t_state *state, int argc, char *argv[])
{
	memset(state, 0, sizeof(t_state));
	init_state_parameters(state, argc, argv);
	state->philos = (t_philo *)malloc(state->n_philos * sizeof(t_philo));
	return (1);
}

int	free_state(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	if (state->philos)
	{
		while (n_philo < state->n_philos)
			pthread_mutex_destroy(&state->philos[n_philo++].creation_mutex);
		free(state->philos);
	}
	n_philo = 0;
	if (state->fork_mutex)
	{
		while (n_philo < state->n_philos)
			pthread_mutex_destroy(&state->fork_mutex[n_philo++]);
		free(state->fork_mutex);
	}
	pthread_mutex_destroy(&state->fork_taking_mutex);
	memset(state, 0, sizeof(t_state));
	return (1);
}
