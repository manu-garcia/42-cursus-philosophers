/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:56:19 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 15:08:14 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "philo_factory.h"
#include "philo_mutex.h"

#include <stdio.h>
#include "atime.h"
#include "log.h"

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
