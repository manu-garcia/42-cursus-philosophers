/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/25 18:38:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "state.h"
#include "atime.h"

static void	log_msg(long milliseconds, int n_philo, char *message)
{
	printf("%ld %d %s\n", milliseconds, n_philo + 1, message);
}

void	log_philo_msg(t_philo *philo, char *message)
{
	long	ms_from_begining;

	ms_from_begining = get_milliseconds_now() - philo->start_time;
	log_msg(ms_from_begining, philo->n_philo, message);
}
