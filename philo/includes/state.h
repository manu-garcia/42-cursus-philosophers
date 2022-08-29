/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/08/29 20:18:57 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <pthread.h>

typedef struct s_fork {
	pthread_mutex_t	mutex;
	int				taken;
}	t_fork;

typedef struct s_philosopher {
	int				n_philo;
	pthread_t		thread;
	pthread_mutex_t	creation_mutex;
	int				n_forks;
	int				n_times_eaten;
	t_fork			*fork_left;
	t_fork			*fork_right;
	pthread_mutex_t	*fork_taking_mutex;
	pthread_mutex_t	death_mutex;
	long			start_time;
	long			last_time_ate;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				ntimes_must_eat;
	void			*state;
}	t_philo;

typedef struct s_state {
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntimes_must_eat;
	t_fork			*fork_mutex;
	pthread_mutex_t	fork_taking_mutex;
}	t_state;

int	init_state(t_state *state, int argc, char *argv[]);
int	free_state(t_state *state);

#endif