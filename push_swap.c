/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:05:08 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:09:14 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

void	which_sort_need_me(t_list **stack_a, t_list **stack_b, int count_nodes)
{
	if (count_nodes == 1)
		return ;
	if (is_sorted(*stack_a) == 1)
		return ;
	if (count_nodes == 2)
		sa(stack_a, 1);
	else if (count_nodes == 3)
		sort_with_3_elements(stack_a);
	else if (count_nodes <= 5)
		sort_with_5_elements(stack_a, stack_b, count_nodes);
	else
		sort_with_batterfly(stack_a, stack_b, count_nodes);
}

void	set_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*cur;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	cur = *stack;
	while (cur)
	{
		tmp = *stack;
		while (tmp)
		{
			if (cur->num > tmp->num)
				cur->index += 1;
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_nodes;

	count_nodes = 0;
	stack_a = NULL;
	stack_b = NULL;
	q_input_is_empty_or_only_spaces(argv);
	validation(argc, argv, &stack_a, &count_nodes);
	set_index(&stack_a);
	which_sort_need_me(&stack_a, &stack_b, count_nodes);
	ft_lstclear(&stack_a);
	return (0);
}
// int main(int argc, char **argv)
// {
// 	main_a(argc,argv);
	//system("leaks push_swap");
// }
