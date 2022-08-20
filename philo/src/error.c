/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:19:49 by manu              #+#    #+#             */
/*   Updated: 2022/08/20 16:47:14 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "state.h"
#include "error.h"

static void	exit_with_code(int code, t_state *state)
{
	free_state(state);
	exit(code);
}

int	exit_with_error(char *message_error, t_state *state)
{
	printf("%s", message_error);
	exit_with_code(ERROR_GENERIC, state);
	return (0);
}

int	exit_without_error(t_state *state)
{
	exit_with_code(ERROR_NONE, state);
	return (0);
}
