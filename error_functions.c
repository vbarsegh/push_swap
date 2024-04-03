/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:11:30 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/10 21:11:48 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(t_list **stack_a)
{
	ft_lstclear(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split_line(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((str[i] == '-' || str[i] == '+' ) && str[i + 1] == '0')
		i++;
	while ((str[i] && str[i] == '0'))
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}
