/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 18:53:10 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#include "state.h"
#include "error.h"

void	*fn(void *param)
{
	t_philo	*me;

	me = (t_philo *)param;
	printf("New thread created for philo number %d\n", me->n_philo);
	while (1)
		;
}

int	create_philo(t_state *state, int n_philo)
{
	t_philo	*philo;

	philo = &state->philos[n_philo];
	philo->n_philo = n_philo;
	if (pthread_create(&philo->thread, NULL, &fn, philo) != 0)
		return (exit_with_error("Error creating thread.\n", state));
	// if (pthread_join(philo->thread, NULL) != 0)
	// 	return (exit_with_error("Error joining philosopher thread.\n", state));
	return (1);
}

int	create_all_philos(t_state *state)
{
	int	n_philo;

	n_philo = 0;
	while (n_philo < state->n_philos)
	{
		create_philo(state, n_philo);
		n_philo++;
	}
	return (1);
}
