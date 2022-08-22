/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/22 19:11:34 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "state.h"
#include "log.h"

void	*philo_thread(void *param)
{
	t_philo	*me;

	me = (t_philo *)param;
	pthread_mutex_lock(&me->creation_mutex);
	while (1)
	{
		pthread_mutex_lock(me->fork_taking_mutex);
		pthread_mutex_lock(me->fork_left);
		log_msg(1, me->n_philo, "has taken a fork");
		if (me->n_forks > 1)
		{
			pthread_mutex_lock(me->fork_right);
			log_msg(1, me->n_philo, "has taken a fork");
			fflush(stdout);
		}
		pthread_mutex_unlock(me->fork_taking_mutex);
		usleep(3000000);
		pthread_mutex_unlock(me->fork_left);
		pthread_mutex_unlock(me->fork_right);
		log_msg(1, me->n_philo, "is eating");
		log_msg(1, me->n_philo, "is sleeping");
		log_msg(1, me->n_philo, "is thinking");
		log_msg(1, me->n_philo, "died");
		return (NULL);
	}
}
