/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/29 20:00:27 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MUTEX_H
# define PHILO_MUTEX_H

# include "state.h"

int		unlock_all_philo_creation_mutex(t_state *state);
int		init_all_fork_mutex(t_state *state);
void	take_fork(t_philo *philo, t_fork *fork);
void	leave_fork(t_fork *fork);

#endif