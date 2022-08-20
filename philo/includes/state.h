/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 16:55:14 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef struct s_philosopher {
	int	n_philosopher;
}	t_philo;

typedef struct s_state {
	t_philo	*philos;
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		ntimes_must_eat;
}	t_state;

int	init_state(t_state *state, int argc, char *argv[]);
int	free_state(t_state *state);

#endif