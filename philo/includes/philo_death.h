/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:55:33 by manu              #+#    #+#             */
/*   Updated: 2022/08/26 11:59:01 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEATH_H
# define PHILO_DEATH_H

int	check_if_dead(t_philo *philo);
int	check_if_any_dead(t_state *state);

#endif