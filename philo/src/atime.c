/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:23:41 by manu              #+#    #+#             */
/*   Updated: 2022/08/25 18:38:28 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long	get_milliseconds_now(void)
{
	struct timeval	now;
	long			milliseconds;

	gettimeofday(&now, NULL);
	milliseconds = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (milliseconds);
}

long	get_milliseconds_diff(struct timeval timer)
{
	long			milliseconds;

	milliseconds = get_milliseconds_now();
	milliseconds -= (timer.tv_sec * 1000) + (timer.tv_usec / 1000);
	return (milliseconds);
}

void	custom_sleep(long milliseconds)
{
	long	start;

	start = get_milliseconds_now();
	while (get_milliseconds_now() - start < milliseconds)
		usleep(10);
}
