/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:18:03 by asmati            #+#    #+#             */
/*   Updated: 2025/10/23 18:35:53 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	error_print(void)
{
	ft_printf("Error\n");
	return (0);
}

int	if_char(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
	{
		if (!ft_isdigit(str[i + 1]))
			return (error_print(), 0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (error_print(), 0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_node *head)
{
	t_node	*node;
	t_node	*tmp;

	node = head;
	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (0);
}

int	parse_and_add(t_node **list, char *arg)
{
	int	value;

	if (!if_char(arg) || !max(arg))
		return (0);
	value = ft_atoi(arg);
	addend_node(list, value);
	return (1);
}

int	parse_args(int argc, char **argv, t_node **stack_a, int i)
{
	char	**split;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !split[0])
			return (free_split(split), 0);
		i = 0;
		while (split[i])
			if (!parse_and_add(stack_a, split[i++]))
				return (free_list(stack_a), free_split(split), 0);
		free_split(split);
	}
	else
	{
		i = 1;
		while (i < argc)
			if (!parse_and_add(stack_a, argv[i++]))
				return (free_list(stack_a), 0);
	}
	if (has_duplicates(*stack_a))
		return (free_list(stack_a), error_print(), 0);
	return (1);
}
