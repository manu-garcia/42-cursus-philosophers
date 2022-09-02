/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/09/02 11:51:36 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "state.h"
#include "atime.h"

void	log_philo_msg(t_philo *philo, char *message)
{
	long	ms_from_begining;

	if (!philo->is_dead)
	{
		pthread_mutex_lock(philo->death_mutex);
		ms_from_begining = get_milliseconds_now() - philo->start_time;
		printf("%ld %d %s\n", ms_from_begining, philo->n_philo + 1, message);
		pthread_mutex_unlock(philo->death_mutex);
	}
}

void	log_msg(t_state *state, char *message)
{
	long	ms_from_begining;

	ms_from_begining = get_milliseconds_now() - state->simulation_start_time;
	printf("%ld Main: %s\n", ms_from_begining, message);
}
