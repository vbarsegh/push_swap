/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top_2_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:26:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:12:08 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_topp_two_elems(t_list **stack)
{
	long long	swap;
	t_list		*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	swap = tmp->num;
	tmp->num = tmp->next->num;
	tmp->next->num = swap;
}

void	sa(t_list **stack_a, int i)
{
	swap_topp_two_elems(stack_a);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int i)
{
	swap_topp_two_elems(stack_b);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int i)
{
	sa(stack_a, i);
	sb(stack_b, i);
}
