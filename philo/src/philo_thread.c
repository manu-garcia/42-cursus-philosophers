/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/22 18:54:59 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "state.h"

void	*philo_thread(void *param)
{
	t_philo	*me;

	me = (t_philo *)param;
	printf("New thread created for philo number %d. Waiting...\n", me->n_philo);
	fflush(stdout);
	pthread_mutex_lock(&me->creation_mutex);
	printf("Philo cration mutex unlocked (philo_id = %d)\n", me->n_philo);
	fflush(stdout);
	while (1)
	{
		pthread_mutex_lock(me->fork_taking_mutex);
		pthread_mutex_lock(me->fork_left);
		printf("Has taken a fork (left) (philo_id = %d)\n", me->n_philo);
		fflush(stdout);
		pthread_mutex_lock(me->fork_right);
		printf("Has taken a fork (right) (philo_id = %d)\n", me->n_philo);
		fflush(stdout);
		pthread_mutex_unlock(me->fork_taking_mutex);
		usleep(3000000);
		pthread_mutex_unlock(me->fork_left);
		pthread_mutex_unlock(me->fork_right);
		printf("Philo number %d doing stuff.\n", me->n_philo);
		fflush(stdout);
		// exit(0);
		return (NULL);
	}
}
