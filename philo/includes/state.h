/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 18:46:21 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <pthread.h>

typedef struct s_philosopher {
	int			n_philo;
	pthread_t	thread;
}	t_philo;

typedef struct s_state {
	t_philo			*philos;
	t_philo			*current_philo;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntimes_must_eat;
	pthread_mutex_t	creation_mutex;
}	t_state;

int	init_state(t_state *state, int argc, char *argv[]);
int	free_state(t_state *state);

#endif