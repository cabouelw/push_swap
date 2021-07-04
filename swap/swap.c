/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:40:38 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 17:17:52 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_swap(t_push_swap *ps, int msg)
{
	if (msg)
	{
		swap(&ps->stack_a, "ss");
		swap(&ps->stack_b, "\n");
	}
	else
	{
		swap(&ps->stack_a, NULL);
		swap(&ps->stack_b, NULL);
	}
}

void	swap(t_stack **stack, char *msg)
{
	int	v;

	if (!*stack || !(*stack)->next)
		return ;
	v = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = v;
	ft_putstr_fd(msg, 1);
}

void	rotate(t_stack **stack, char *msg)
{
	t_stack	*last;
	t_stack	*next;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	next = *stack;
	while (next->next)
		next = next->next;
	next->next = last;
	ft_putstr_fd(msg, 1);
}

void	rotate_r(t_stack **stack, char *msg)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_putstr_fd(msg, 1);
}

void	push(t_stack **pop, t_stack **push, char *msg)
{
	t_stack	*first;

	if (!(*pop))
		return ;
	first = *pop;
	*pop = (*pop)->next;
	first->next = *push;
	*push = first;
	ft_putstr_fd(msg, 1);
}
