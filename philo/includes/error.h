/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:20:13 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 16:41:11 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_NONE			0
# define ERROR_GENERIC		1

int	exit_with_error(char *message_error, t_state *state);
int	exit_without_error(t_state *state);

#endif
