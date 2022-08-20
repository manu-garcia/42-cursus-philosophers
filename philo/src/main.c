/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:56:19 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 16:55:16 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "state.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	init_state(&state, argc, argv);
	printf("state.n_philosophers = %d\n", state.n_philos);
	printf("state.time_to_die = %d\n", state.time_to_die);
	printf("state.time_to_eat = %d\n", state.time_to_eat);
	printf("state.time_to_sleep = %d\n", state.time_to_sleep);
	printf("state.ntimes_must_eat = %d\n", state.ntimes_must_eat);
	free_state(&state);
	return (0);
}
