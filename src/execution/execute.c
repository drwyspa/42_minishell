/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:39:57 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/06 21:51:34 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_code;


// Prepares for execution. Creating pipes and 
// checks output and input files. 
// True for ready, false for failure.
static int	prep_for_exec(t_data *data)
{
	if (!data || !data->cmd)
		return (EXIT_SUCCESS);
	if(!data->cmd->cmd)
}

// Takes command from user and executed it by creating children processes.
// Waiting for terminate all those processes.
// Passing exit code from last child or exut code 1 if fail of child
// process creation.
int	execute(t_data *data)
{
	int	ret;

	ret = prep_for_exec(data);/////
}