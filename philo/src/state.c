/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:22:30 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 18:54:59 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "state.h"
#include "error.h"
#include "ft_atoi.h"

int	init_state(t_state *state, int argc, char *argv[])
{
	memset(state, 0, sizeof(t_state));
	if (argc < 5 || argc > 6)
		return (exit_with_error("Error. Invalid arguments\n", state));
	state->n_philos = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->ntimes_must_eat = ft_atoi(argv[5]);
	state->philos = (t_philo *)malloc(state->n_philos * sizeof(t_philo));
	pthread_mutex_init(&state->creation_mutex, NULL);
	return (1);
}

int	free_state(t_state *state)
{
	if (state->philos)
		free(state->philos);
	pthread_mutex_destroy(&state->creation_mutex);
	memset(state, 0, sizeof(t_state));
	return (1);
}
