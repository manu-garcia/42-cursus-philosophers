/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:56:19 by manu              #+#    #+#             */
/*   Updated: 2022/09/02 09:40:33 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "philo_factory.h"
#include "philo_mutex.h"

#include <stdio.h>
#include "atime.h"
#include "log.h"

/*
static void	measure_lag(t_state *state)
{
	int		ntimes;
	int		i;
	long	end_time;
	int		diff;
	long	ms;

	ms = 100;
	ntimes = 100;
	i = 0;
	state->simulation_start_time = get_milliseconds_now();
	log_msg(state, "Before...");
	custom_sleep(ms, NULL);
	log_msg(state, "After.");
	state->simulation_start_time = get_milliseconds_now();
	while (i < ntimes)
	{
		custom_sleep(ms, NULL);
		i++;
	}
	end_time = get_milliseconds_now();
	diff = end_time - state->simulation_start_time;
	printf("Number times executed (%d)\n", ntimes);
	printf("Number ms to wait each time (%ld)\n", ms);
	printf("Expected ms spent (%ldms)\n", ms * ntimes);
	printf("Real ms spent (%dms)\n", diff);
	printf("Average lagged ms (%dms), when %ld expected\n", diff / ntimes, ms);
	// printf("Average lagged ms (%ldms), when 0 expected\n", (diff - (ms * ntimes)) / ntimes);
}
*/

int	main(int argc, char *argv[])
{
	t_state	state;

	init_state(&state, argc, argv);
	init_all_fork_mutex(&state);
	create_all_philos(&state);
	wait_for_all_philos(&state);
	// measure_lag(&state);
	free_state(&state);
	return (0);
}
