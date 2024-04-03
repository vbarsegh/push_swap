/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:16:09 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:06:36 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	if (stack_1 == NULL || stack_2 == NULL || (*stack_2) == NULL)
		return ;
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_2 != NULL)
		(*stack_2)->prev = NULL;
	tmp->next = *stack_1;
	if (*stack_1 != NULL)
		(*stack_1)->prev = tmp;
	*stack_1 = tmp;
}

void	pa(t_list **stack_1, t_list **stack_2, int i)
{
	push(stack_1, stack_2);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_1, t_list **stack_2, int i)
{
	push(stack_2, stack_1);
	if (i == 1)
		write(1, "pb\n", 3);
}
