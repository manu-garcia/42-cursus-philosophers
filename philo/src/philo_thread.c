/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/25 19:05:46 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // exit
#include <stdio.h> // printf

#include "state.h"
#include "log.h"
#include "atime.h"

static int	check_if_dead(t_philo *philo)
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

static int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_taking_mutex);
	pthread_mutex_lock(philo->fork_left);
	log_philo_msg(philo, "has taken a fork");
	if (philo->n_forks > 1)
	{
		pthread_mutex_lock(philo->fork_right);
		log_philo_msg(philo, "has taken a fork");
	}
	pthread_mutex_unlock(philo->fork_taking_mutex);
	// log_philo_msg(philo, "Fork taking mutex unlocked");
	if (check_if_dead(philo))
		return (0);
	log_philo_msg(philo, "is eating");
	// printf("Waiting %ld ms...\n", philo->time_to_eat);
	custom_sleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	philo->last_time_ate = get_milliseconds_now();
	return (1);
}

static int	philo_sleep(t_philo *philo)
{
	log_philo_msg(philo, "is sleeping");
	custom_sleep(philo->time_to_sleep);
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
