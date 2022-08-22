/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:56:19 by manu              #+#    #+#             */
/*   Updated: 2022/08/22 18:50:58 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "philo_factory.h"
#include "philo_mutex.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	init_state(&state, argc, argv);
	init_all_fork_mutex(&state);
	create_all_philos(&state);
	wait_for_all_philos(&state);
	free_state(&state);
	return (0);
}
