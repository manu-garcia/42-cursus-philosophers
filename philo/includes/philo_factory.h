/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:00:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 19:09:40 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FACTORY_H
# define PHILO_FACTORY_H

# include "state.h"

int	create_philo(t_state *state, int n_philo);
int	create_all_philos(t_state *state);
int	wait_for_all_philos(t_state *state);

#endif