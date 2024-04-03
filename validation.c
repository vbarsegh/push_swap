/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:27:34 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/16 20:07:10 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validation(int argc, char **argv, t_list **stack_a, int *count_nodes)
{
	int			i;
	char		**arr;
	long long	num;
	int			j;

	i = 1;
	while (i < argc)
	{
		arr = split(argv[i]);
		if (!arr)
			exit_program(stack_a);
		j = 0;
		while (arr[j])
		{
			(*count_nodes)++;
			if (check_string(arr[j]) == 0)
				exit_program(stack_a);
			num = ft_atoll(arr[j]);
			foo(stack_a, num, arr[j++]);
		}
		free_split_line(arr);
		i++;
	}
	if (check_have_dublucates(*stack_a) == 0)
		exit_program(stack_a);
}

void	foo(t_list **stack_a, long long num, char *str)
{
	t_list	*node;

	node = NULL;
	if (check_number(num, stack_a, str) == 1)
	{
		node = ft_lstnew(num);
		ft_lstadd_back(stack_a, node);
	}
	else
		exit_program(stack_a);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')
			|| (str[i] == 32))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_number(long long num, t_list **stack_a, char *str)
{
	if (num > INT_MAX || num < INT_MIN || ft_strlen(str) > 11)
		exit_program(stack_a);
	return (1);
}

int	check_have_dublucates(t_list *stack_a)
{
	t_list		*tmp;
	long long	numb;

	while (stack_a)
	{
		tmp = stack_a->next;
		numb = stack_a->num;
		while (tmp)
		{
			if (numb == tmp->num)
			{
				return (0);
			}
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}
