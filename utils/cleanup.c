/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:39:54 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/03 19:48:19 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Frees a pointer of any type if it is not NULL and sets it to NULL.
// This avoids accidental double-frees.
void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
//Frees an array of strings.
void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

// Frees all the data. If flag clear_history is true - 
// frees environment and command history before running 
// the program.
void	free_data(t_data *data, bool clear_history)
{
	if (data && data->usr_input)
	{
		free_ptr(data->usr_input);
		data->usr_input = NULL;
	}
	if (data && data->token)
		lstclear_token(&data->token, &free_ptr);/////
	if (data && &data->cmd)
		lst_clear_cmd(&data->cmd, &free_ptr);//////
	if (clear_history == true)
	{
		if (data && data->working_dir)
			free_ptr(data->working_dir);
		if (data && data->old_working_dir)
			free_ptr(data->old_working_dir);
		if (data && data->env)
			free_str_tab(data->env);
		rl_clear_history();
	}

}

// Closes all file descriptors. 
// If flag close_backups is true - also closes backup STDIN 
// and STDOUT fd's.
void	close_fds(t_command *cmds, bool close_backups)
{

}