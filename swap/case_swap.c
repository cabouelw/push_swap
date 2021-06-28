/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:28:13 by cabouelw          #+#    #+#             */
/*   Updated: 2021/06/28 20:24:58 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	case_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int third;

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

void	pup_min(int	idx, t_stack **stack_a, t_stack **stack_b, int size)
{
	int i;

	i = 0;
	 //     5 4 1 9 3 0 6
	while (i < idx && idx < (size / 2))
	{
		rotate(stack_a, "ra\n");
		i++;
	}
	// printf("[%d]\n",(*stack_a)->value);
	i = size;
	while (i > idx && idx >= (size / 2))
	{
		rotate_r(stack_a, "rra\n");
		i--;
	}
	push(stack_a, stack_b, "pb\n");
}

void	swap_from_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *swap;
	int		size;

	size = 0;
	swap = *stack_b;
	while (swap)
	{
		size++;
		swap = swap->next;
	}
	swap = *stack_b;
	while (size)
	{
		size--;
		push(&swap, stack_a, "pb\n");
	}
	(*stack_b) = NULL;
}

void	push_and_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		idx;
	int		j;
	// t_stack *stage;
	t_stack	*loop_a;
	t_stack	*loop_b;

	min = *stack_a;
	loop_b = *stack_b;
	while ((*stack_a)->next)
	{
		loop_a = *stack_a;
		j = 0;
		min = *stack_a;
		while (loop_a)
		{
			if (loop_a->value < min->value)
			{
				// printf("----------------{%d} < min{%d}\n", loop_a->value, min->value);
				min = loop_a;
				idx = j;
			}
			loop_a = loop_a->next;
			j++;
		}
		// printf("\n\nmin******|%d|%d|\n\n", min->value, idx);
		pup_min(idx, stack_a, stack_b, j);
		// stage = stage->next;
	}
	push(stack_a, stack_b, "pb\n");
	swap_from_b(stack_a, stack_b);
}