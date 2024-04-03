/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:07:38 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/14 19:48:11 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_with_batterfly(t_list **stack_a, t_list **stack_b, int size_nodes)
{
	int	n;
	int	offset;

	n = 0;
	offset = my_sqrt(size_nodes) + xoranard_sqrt(size_nodes);
	while (*stack_a)
	{
		if ((*stack_a)->index <= n)
		{
			pb(stack_a, stack_b, 1);
			rotate_stack_b(stack_b, 1);
			n++;
		}
		else if ((*stack_a)->index <= n + offset)
		{
			pb(stack_a, stack_b, 1);
			n++;
		}
		else
			rotate_stack_a(stack_a, 1);
	}
	push_b_elem_in_a(stack_a, stack_b, size_nodes);
}

void	push_b_elem_in_a(t_list **stack_a, t_list **stack_b, int size_nodes)
{
	int	i;

	i = size_nodes - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == i)
		{
			pa(stack_a, stack_b, 1);
			i--;
			size_nodes--;
		}
		else if (get_position(*stack_b, i) >= size_nodes / 2 + 1)
			reverse_rotate_stack_b(stack_b, 1);
		else
			rotate_stack_b(stack_b, 1);
	}
}

int	get_position(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	my_sqrt(int num)
{
	int	i;

	i = 0;
	while (i < num / 2)
	{
		if (i * i >= num)
			return (i);
		i++;
	}
	return (-1);
}

int	xoranard_sqrt(int num)
{
	int	i;

	i = 0;
	while (i <= num / 9)
	{
		if (i * i * i >= num)
			return (i);
		i++;
	}
	return (-1);
}
