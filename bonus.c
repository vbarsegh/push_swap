/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:41:14 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:03:22 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_sort_write(t_list **stack_a, t_list **stack_b, char *buffer)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
	{
		sa(stack_a, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "sb\n") == 0)
	{
		sb(stack_b, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "ss\n") == 0)
	{
		ss(stack_a, stack_b, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "pa\n") == 0)
	{
		pa(stack_a, stack_b, 0);
		return (1);
	}
	if (func_1(stack_a, stack_b, buffer) == 1)
		return (1);
	else if (func_2(stack_a, stack_b, buffer) == 1)
		return (1);
	return (-1);
}

int	func_1(t_list **stack_a, t_list **stack_b, char *buffer)
{
	if (ft_strcmp(buffer, "pb\n") == 0)
	{
		pb(stack_a, stack_b, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "ra\n") == 0)
	{
		rotate_stack_a(stack_a, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "rb\n") == 0)
	{
		rotate_stack_b(stack_b, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "rr\n") == 0)
	{
		rotate_stack_a_and_b(stack_a, stack_b, 0);
		return (1);
	}
	return (-1);
}

int	func_2(t_list **stack_a, t_list **stack_b, char *buffer)
{
	if (ft_strcmp(buffer, "rra\n") == 0)
	{
		reverse_rotate_stack_a(stack_a, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "rrb\n") == 0)
	{
		reverse_rotate_stack_b(stack_b, 0);
		return (1);
	}
	if (ft_strcmp(buffer, "rrr\n") == 0)
	{
		reverse_rotate_stack_a_and_b(stack_a, stack_b, 0);
		return (1);
	}
	return (-1);
}

void	bonus_checker(t_list **stack_a, t_list **stack_b, char *buffer)
{
	while (buffer != NULL)
	{
		if (which_sort_write(stack_a, stack_b, buffer) != 1)
		{
			free(buffer);
			exit(write(2, "Error\n", 6));
		}
		free(buffer);
		buffer = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_nodes;
	char	*buffer;

	count_nodes = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	q_input_is_empty_or_only_spaces(argv);
	validation(argc, argv, &stack_a, &count_nodes);
	buffer = get_next_line(0);
	bonus_checker(&stack_a, &stack_b, buffer);
	if (is_sorted(stack_a) == 1 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	return (0);
}
// int main(int argc, char **argv)
// {
// 	main_a(argc,argv);
// 	system("leaks checker");
// }