/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:23:56 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:35:09 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_list	**stack)
{
	t_list	*tmp;
	t_list	*variable;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		variable = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
	variable->next = NULL;
}

void	reverse_rotate_stack_a(t_list	**stack_a, int i)
{
	reverse_rotate_stack(stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_stack_b(t_list	**stack_b, int i)
{
	reverse_rotate_stack(stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_stack_a_and_b(t_list	**stack_a, t_list **stack_b, int i)
{
	reverse_rotate_stack_a(stack_a, i);
	reverse_rotate_stack_b(stack_b, i);
}
