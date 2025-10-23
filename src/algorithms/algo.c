/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:17:03 by asmati            #+#    #+#             */
/*   Updated: 2025/10/23 19:15:25 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*algo2choice(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->a;
	second = first->next;
	if (first->value > second->value)
		return (swap_a(&stack->a), stack->a);
	return (stack->a);
}

t_node	*algo_3choice(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		if (second->value > third->value)
			return (swap_a(&stack->a), reverse_rotate(&stack->a), stack->a);
		else
			return (rotate_stack(&stack->a), stack->a);
	}
	else if (second->value > first->value && second->value > third->value)
	{
		if (first->value > third->value)
			return (reverse_rotate(&stack->a), stack->a);
		else
			return (swap_a(&stack->a), rotate_stack(&stack->a), stack->a);
	}
	else if (first->value > second->value)
		return (swap_a(&stack->a), stack->a);
	return (stack->a);
}

static void	push_min_to_b(t_stack *stack)
{
	t_node	*min;
	t_node	*temp;
	int		pos;
	int		len;

	len = list_len_a(stack);
	min = find_min(stack->a);
	pos = 0;
	temp = stack->a;
	while (temp && temp != min)
	{
		pos++;
		temp = temp->next;
	}
	while (stack->a != min)
	{
		if (pos <= len / 2)
			rotate_stack(&stack->a);
		else
			reverse_rotate(&stack->a);
	}
	push_b(&stack);
}

t_node	*algo_5choice(t_stack *stack)
{
	int	i;

	i = 0;
	if (list_len_a(stack) == 4)
		i = 1;
	while (i < 2)
	{
		push_min_to_b(stack);
		i++;
	}
	algo_3choice(stack);
	push_a(&stack);
	push_a(&stack);
	return (stack->a);
}

void	radix_sort(t_stack *stack)
{
	int	max_bits;
	int	i;
	int	j;
	int	len;

	max_bits = max_bytes(stack);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		len = list_len_a(stack);
		while (j < len)
		{
			if (((stack->a->index >> i) & 1) == 0)
				push_b(&stack);
			else
				rotate_stack(&stack->a);
			j++;
		}
		while (stack->b)
			push_a(&stack);
		i++;
	}
}
