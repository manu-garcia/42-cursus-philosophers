/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:56:19 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 19:09:58 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "philo_factory.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	init_state(&state, argc, argv);
	pthread_mutex_lock(&state.creation_mutex);
	create_all_philos(&state);
	wait_for_all_philos(&state);
	pthread_mutex_unlock(&state.creation_mutex);
	free_state(&state);
	return (0);
}
