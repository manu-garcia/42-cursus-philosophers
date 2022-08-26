/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/26 12:21:13 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // exit
#include <stdio.h> // printf

#include "state.h"
#include "log.h"
#include "atime.h"

int	check_if_dead(t_philo *philo)
{
	long	time;

	time = (get_milliseconds_now() - philo->last_time_ate);
	if (time > philo->time_to_die)
	{
		log_philo_msg(philo, "died");
		// printf("Took %ld ms to eat...\n", time);
		exit(0);
		return (1);
	}
	return (0);
}

int	check_if_any_dead(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		// check_if_dead(&state->philos[n_philo]);
		n_philo++;
	}
	return (1);
}
