/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:23:41 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 01:27:54 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#include "state.h"
#include "philo_death.h"

#define USLEEP_USEC	1

long	get_milliseconds_now(void)
{
	struct timeval	now;
	long			milliseconds;

	gettimeofday(&now, NULL);
	milliseconds = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (milliseconds);
}

long	get_milliseconds_diff(struct timeval timer)
{
	long			milliseconds;

	milliseconds = get_milliseconds_now();
	milliseconds -= (timer.tv_sec * 1000) + (timer.tv_usec / 1000);
	return (milliseconds);
}

void	custom_sleep(long milliseconds, t_philo *philo)
{
	long	now;
	int		multiplier;

	if (philo)
		multiplier = philo->n_forks;
	else
		multiplier = 1;
	now = get_milliseconds_now();
	while (milliseconds > get_milliseconds_now() - now)
		usleep(USLEEP_USEC * multiplier);
}
