/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:28:13 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 15:58:34 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	case_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third && third > second)
		swap(stack_a, "sa\n");
	if (first > second && first > third && third < second)
	{
		swap(stack_a, "sa\n");
		rotate_r(stack_a, "rra\n");
	}
	if (first > second && first > third && third > second)
		rotate(stack_a, "ra\n");
	if (first < second && first < third && third < second)
	{
		swap(stack_a, "sa\n");
		rotate(stack_a, "ra\n");
	}
	if (first < second && first > third && third < second)
		rotate_r(stack_a, "rra\n");
}

void	push_all(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(stack_b, stack_a, "pa\n");
		i++;
	}
}

void	pop_min(t_stack **stack_a, t_stack **stack_b, int idx, int size)
{
	int	i;

	i = 0;
	while (i < idx && idx < (size / 2))
	{
		rotate(stack_a, "ra\n");
		i++;
	}
	i = size;
	while (i > idx && idx >= (size / 2))
	{
		rotate_r(stack_a, "rra\n");
		i--;
	}
	push(stack_a, stack_b, "pb\n");
}

void	case_less(t_push_swap *ps)
{
	int		idx;
	int		j;

	while (ps->stack_a)
	{
		ps->loop_a = ps->stack_a;
		j = 0;
		ps->min = ps->stack_a;
		while (ps->loop_a)
		{
			if (ps->loop_a->value <= ps->min->value)
			{
				ps->min = ps->loop_a;
				idx = j;
			}
			ps->loop_a = ps->loop_a->next;
			j++;
		}
		pop_min(&ps->stack_a, &ps->stack_b, idx, j);
	}
	push(&ps->stack_a, &ps->stack_b, "pb\n");
	push_all(&ps->stack_a, &ps->stack_b, ps->size);
}

void	case_five(t_push_swap *ps, int size, int idx)
{
	int		nb;

	nb = 0;
	while (nb < 2)
	{
		ps->loop_a = ps->stack_a;
		idx = 0;
		size = 0;
		ps->min = ps->stack_a;
		while (ps->loop_a)
		{
			if (ps->loop_a->value < ps->min->value)
			{
				ps->min = ps->loop_a;
				idx = size;
			}
			ps->loop_a = ps->loop_a->next;
			size++;
		}
		pop_min(&ps->stack_a, &ps->stack_b, idx, size);
		nb++;
	}
	case_three(&ps->stack_a);
	push(&ps->stack_b, &ps->stack_a, "pa\n");
	push(&ps->stack_b, &ps->stack_a, "pa\n");
}
