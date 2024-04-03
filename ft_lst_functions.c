/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:14:19 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/10 21:15:19 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr -> next = new;
	new->prev = ptr;
}

t_list	*ft_lstnew(long long num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> num = num;
	new -> next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
