/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 19:22:30 by manu             ###   ########.fr       */
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
	printf("New thread created for philo number %d\n", me->n_philo);
	while (1)
	{
		usleep(3000000);
		printf("Philo number %d doing stuff.\n", me->n_philo);
		exit(0);
	}
}
