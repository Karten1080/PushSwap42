/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:18:29 by asmati            #+#    #+#             */
/*   Updated: 2025/10/23 18:30:16 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Bib/Libft/libft.h"
# include "../Bib/PRINTF/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

//* === PROTOTYPES PARSING === */
int					error_print(void);
int					if_char(char *str);
long				ft_atol(const char *str);
int					max(const char *str);
int					has_duplicates(t_node *head);
void				addend_node(t_node **head, int value);
t_node				*new_node(int value);
void				free_list(t_node **head);
void				free_split(char **str);
int					parse_and_add(t_node **list, char *arg);
int					parse_args(int argc, char **argv, t_node **stack_a, int i);
int					is_sorted(t_stack *pile);
void				free_all(t_stack *stack);

//* === PROTOTYPES ALGO / UTILS === */
int					list_len_a(t_stack *stack);
int					list_len_b(t_stack *stack);
void				algo_redirect(t_stack *stack);
t_node				*algo2choice(t_stack *stack);
t_node				*algo_3choice(t_stack *stack);
t_node				*find_min(t_node *stack);
t_node				*algo_5choice(t_stack *stack);
void				assign_bytes(t_node *stack);
void				radix_sort(t_stack *stack);
int					max_bytes(t_stack *stack);

//* === PROTOTYPES OPERATIONS === */
void				swap_a(t_node **stack);
void				push_a(t_stack **stack);
void				push_b(t_stack **stack);
void				rotate_stack(t_node **stack);
void				reverse_rotate(t_node **stack);

#endif
