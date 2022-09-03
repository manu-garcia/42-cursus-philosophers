/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:07:32 by manu              #+#    #+#             */
/*   Updated: 2022/09/03 15:08:03 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H

# include "state.h"

void	calc_stats(t_state	*state);
void	show_stats(t_state	*state);
void	measure_lag(t_state *state);

#endif
