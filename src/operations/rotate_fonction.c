/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/07/27 02:26:40 by asmati            #+#    #+#             */
/*   Updated: 2025/07/27 02:26:40 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	ft_printf("sa\n");
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push_a(t_stack **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->b)
	{
		return ;
	}
	ft_printf("pa\n");
	temp = (*stack)->b;
	(*stack)->b = (*stack)->b->next;
	temp->next = (*stack)->a;
	(*stack)->a = temp;
}

void	push_b(t_stack **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->a)
	{
		return ;
	}
	ft_printf("pb\n");
	temp = (*stack)->a;
	(*stack)->a = (*stack)->a->next;
	temp->next = (*stack)->b;
	(*stack)->b = temp;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	ft_printf("rra\n");
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	ft_printf("ra\n");
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}
