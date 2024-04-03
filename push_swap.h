/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:37:33 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/03/12 20:18:26 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	long long		num;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void		foo(t_list **stack_a, long long num, char *str);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(long long num);
void		exit_program(t_list **stack_a);
void		free_split_line(char **arr);
int			check_string(char *str);
char		**split(char const *s);
long long	ft_atoll(const char *nptr);
int			check_number(long long num, t_list **stack_a, char *str);
void		validation(int argc, char **argv, t_list **stack_a,
				int *count_nodes);
int			check_have_dublucates(t_list *stack_a);
void		ft_lstclear(t_list **lst);
void		swap_topp_two_elems(t_list **stack);
void		sa(t_list **stack_a, int i);
void		sb(t_list **stack_b, int i);
void		ss(t_list **stack_a, t_list **stack_b, int i);
void		push(t_list **stack_1, t_list **stack_2);
void		pa(t_list **stack_1, t_list **stack_2, int i);
void		pb(t_list **stack_1, t_list **stack_2, int i);
void		rotate_stack(t_list **stack);
void		rotate_stack_a(t_list	**stack_a, int i);
void		rotate_stack_b(t_list	**stack_b, int i);
void		rotate_stack_a_and_b(t_list	**stack_a, t_list **stack_b, int i);
void		reverse_rotate_stack(t_list	**stack);
void		reverse_rotate_stack_a(t_list	**stack_a, int i);
void		reverse_rotate_stack_b(t_list	**stack_b, int i);
void		reverse_rotate_stack_a_and_b(t_list	**stack_a,
				t_list **stack_b, int i);
void		sort_with_3_elements(t_list **stack);
void		sort_with_5_elements(t_list **stack_a,
				t_list **stack_b, int count_nodes);
int			get_position(t_list *stack, int index);
void		set_index(t_list **stack);
void		sort_with_batterfly(t_list **stack_a, t_list **stack_b,
				int size_nodes);
void		push_b_elem_in_a(t_list **stack_a, t_list **stack_b,
				int size_nodes);
void		which_sort_need_me(t_list **stack_a, t_list **stack_b,
				int count_nodes);
int			is_sorted(t_list *stack);
int			xoranard_sqrt(int num);
int			my_sqrt(int num);
int			is_white_space(char c);
void		q_input_is_empty_or_only_spaces(char **argv);
int			ft_strcmp(char *s1, char *s2);
char		*get_next_line(int fd);
int			func_2(t_list **stack_a, t_list **stack_b, char *buffer);
int			func_1(t_list **stack_a, t_list **stack_b, char *buffer);
int			which_sort_write(t_list **stack_a, t_list **stack_b,
				char *buffer);
void		bonus_checker(t_list **stack_a, t_list **stack_b, char *buffer);
int			ft_strlen(char *str);

#endif
