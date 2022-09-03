/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:55:33 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 15:17:18 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEATH_H
# define PHILO_DEATH_H

int	check_if_dead(t_philo *philo);
int	check_if_any_dead_or_finished(t_state *state);
int	check_if_all_started(t_state *state);
int	check_if_all_finished(t_state *state);
int	set_all_dead(t_state *state);

#endif
