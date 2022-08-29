/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/29 18:29:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // exit
#include <stdio.h> // printf

#include "state.h"
#include "log.h"
#include "atime.h"
#include "philo_death.h"

static int	philo_eat(t_philo *philo)
{
	if (philo->ntimes_must_eat > 0
		&& philo->n_times_eaten >= philo->ntimes_must_eat)
			return (0);
	pthread_mutex_lock(philo->fork_taking_mutex);
	pthread_mutex_lock(philo->fork_left);
	log_philo_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_right);
	log_philo_msg(philo, "has taken a fork");
	pthread_mutex_unlock(philo->fork_taking_mutex);
	// log_philo_msg(philo, "Fork taking mutex unlocked");
	if (check_if_dead(philo))
		return (0);
	log_philo_msg(philo, "is eating");
	// printf("Waiting %ld ms...\n", philo->time_to_eat);
	custom_sleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	philo->last_time_ate = get_milliseconds_now();
	philo->n_times_eaten += 1;
	return (1);
}

static int	philo_sleep(t_philo *philo)
{
	log_philo_msg(philo, "is sleeping");
	custom_sleep(philo->time_to_sleep, philo);
	return (1);
}

static int	philo_think(t_philo *philo)
{
	log_philo_msg(philo, "is thinking");
	return (1);
}

void	*philo_thread(void *param)
{
	t_philo	*me;

	me = (t_philo *)param;
	me->start_time = get_milliseconds_now();
	me->last_time_ate = me->start_time;
	pthread_mutex_lock(&me->creation_mutex);
	me->start_time = get_milliseconds_now();
	me->last_time_ate = me->start_time;
	while (1)
	{
		if (!philo_eat(me))
			break ;
		philo_sleep(me);
		philo_think(me);
	}
	return (NULL);
}
