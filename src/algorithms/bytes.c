/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:19:06 by asmati            #+#    #+#             */
/*   Updated: 2025/09/29 16:38:13 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	max_bytes(t_stack *stack)
{
	int		max_bytes;
	int		i;
	t_node	*temp;

	temp = stack->a;
	max_bytes = 0;
	i = 0;
	while (temp)
	{
		if (temp->index > i)
			i = temp->index;
		temp = temp->next;
	}
	while ((i >> max_bytes) != 0)
		max_bytes++;
	return (max_bytes);
}

void	assign_bytes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
