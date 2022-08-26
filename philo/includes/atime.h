/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:07:36 by manu              #+#    #+#             */
/*   Updated: 2022/08/26 11:50:58 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATIME_H
# define ATIME_H

# include <sys/time.h>

long	get_milliseconds_diff(struct timeval timer);
long	get_milliseconds_now(void);
void	custom_sleep(long milliseconds, t_philo *philo);

#endif