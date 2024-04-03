/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:24:39 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:38:06 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*variable;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	variable = tmp->next;
	(*stack)->next->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
	*stack = variable;
}

void	rotate_stack_a(t_list	**stack_a, int i)
{
	rotate_stack(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rotate_stack_b(t_list	**stack_b, int i)
{
	rotate_stack(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rotate_stack_a_and_b(t_list	**stack_a, t_list **stack_b, int i)
{
	rotate_stack_a(stack_a, i);
	rotate_stack_b(stack_b, i);
}
