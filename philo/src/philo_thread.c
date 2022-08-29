/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/29 20:11:19 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // exit
#include <stdio.h> // printf

#include "state.h"
#include "log.h"
#include "atime.h"
#include "philo_death.h"
#include "philo_mutex.h"

static int	philo_eat(t_philo *philo)
{
	if (check_if_dead(philo))
		return (0);
	log_philo_msg(philo, "is eating");
	// printf("Waiting %ld ms...\n", philo->time_to_eat);
	custom_sleep(philo->time_to_eat, philo);
	leave_fork(philo->fork_left);
	leave_fork(philo->fork_right);
	philo->last_time_ate = get_milliseconds_now();
	philo->n_times_eaten += 1;
	return (1);
}

static int	philo_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_taking_mutex);
	if (philo->n_forks > 1
		&& !philo->fork_left->taken && !philo->fork_right->taken)
	{
		take_fork(philo, philo->fork_left);
		take_fork(philo, philo->fork_right);
		pthread_mutex_unlock(philo->fork_taking_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->fork_taking_mutex);
	return (0);
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
	t_philo	*philo;

	philo = (t_philo *)param;
	philo->start_time = get_milliseconds_now();
	philo->last_time_ate = philo->start_time;
	pthread_mutex_lock(&philo->creation_mutex);
	philo->start_time = get_milliseconds_now();
	philo->last_time_ate = philo->start_time;
	while (1)
	{
		if (philo_take_forks(philo))
		{
			if (!philo_eat(philo) || (philo->ntimes_must_eat
					&& philo->n_times_eaten >= philo->ntimes_must_eat))
				break ;
			if (check_if_dead(philo))
				break ;
			philo_sleep(philo);
			if (check_if_dead(philo))
				break ;
			philo_think(philo);
		}
		if (check_if_dead(philo))
			break ;
	}
	pthread_mutex_unlock(philo->fork_taking_mutex);
	return (NULL);
}
