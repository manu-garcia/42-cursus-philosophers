/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:55:33 by manu              #+#    #+#             */
/*   Updated: 2022/09/01 16:50:07 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEATH_H
# define PHILO_DEATH_H

int	check_if_dead(t_philo *philo);
int	check_if_any_dead_or_finished(t_state *state);
int	check_if_all_started(t_state *state);
int	check_if_all_finished(t_state *state);
int	check_if_all_ate(t_state *state);
int	set_all_dead(t_state *state);

#endif