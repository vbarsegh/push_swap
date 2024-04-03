/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_and_5_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:10:58 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:37:24 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	find_the_biggest_node_element(t_list	*stack)
{
	long long	elem;
	long long	temp;

	elem = stack->num;
	stack = stack->next;
	if (stack->num > stack->next->num)
		temp = stack->num;
	else
		temp = stack->next->num;
	if (elem > temp)
		return (elem);
	return (temp);
}

void	sort_with_3_elements(t_list	**stack)
{
	t_list		*tmp;
	long long	high_elem;

	tmp = *stack;
	high_elem = find_the_biggest_node_element(tmp);
	if (high_elem == tmp->next->next->num && tmp->next->num > tmp->num)
		return ;
	if ((tmp->num > tmp->next->num) && (tmp->num > tmp->next->next->num))
	{
		rotate_stack_a(stack, 1);
		if (((*stack)->next->num) < ((*stack)->num))
			sa(stack, 1);
	}
	else if (tmp->num < tmp->next->num)
	{
		reverse_rotate_stack_a(stack, 1);
		if ((*stack)->num > (*stack)->next->num)
			sa(stack, 1);
	}
	else
		sa(stack, 1);
}

void	sort_with_5_elements(t_list	**stack_a, t_list **stack_b, int count_argc)
{
	int	i;

	i = 0;
	while (count_argc > 3)
	{
		if (get_position(*stack_a, i) == 0)
		{
			pb(stack_a, stack_b, 1);
			count_argc--;
			i++;
		}
		else if (get_position(*stack_a, i) >= count_argc / 2 + 1)
			reverse_rotate_stack_a(stack_a, 1);
		else
			rotate_stack_a(stack_a, 1);
	}
	sort_with_3_elements(stack_a);
	if ((*stack_b)->next)
	{
		if ((*stack_b)->next->num > (*stack_b)->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	pa(stack_a, stack_b, 1);
}

void	q_input_is_empty_or_only_spaces(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32)
				j++;
			if (argv[i][j] == '\0')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			else
				break ;
		}
		i++;
	}
}
