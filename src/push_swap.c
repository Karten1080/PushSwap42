/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:17:50 by asmati            #+#    #+#             */
/*   Updated: 2025/10/25 14:39:35 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_redirect(t_stack *stack)
{
	int	len;

	assign_bytes(stack->a);
	len = list_len_a(stack);
	if (len == 2)
		algo2choice(stack);
	else if (len == 3)
		algo_3choice(stack);
	else if (len == 5 || len == 4)
		algo_5choice(stack);
	else
		radix_sort(stack);
}

int	list_len_a(t_stack *stack)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = stack->a;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	list_len_b(t_stack *stack)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = stack->b;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	main(int argc, char **argv)
{
	t_stack	*pile;

	pile = malloc(sizeof(t_stack));
	if (!pile)
		return (1);
	pile->a = NULL;
	pile->b = NULL;
	if (!parse_args(argc, argv, &pile->a, 0))
		return (free_list(&pile->a), free(pile), 1);
	if (pile->a && is_sorted(pile) == 0)
		algo_redirect(pile);
	free_list(&pile->a);
	free_list(&pile->b);
	free(pile);
	return (0);
}
