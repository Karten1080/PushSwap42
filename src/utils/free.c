/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:23:47 by asmati            #+#    #+#             */
/*   Updated: 2025/10/25 14:34:54 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_list(t_node **head)
{
	t_node	*tmp;
	t_node	*current;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = NULL;
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
