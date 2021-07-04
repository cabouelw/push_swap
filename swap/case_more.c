/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:50:07 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 17:17:52 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_close(t_push_swap *ps, int key_nb, int size)
{
	int	pos;
	int	i;
	int	check;

	pos = (size / 2);
	i = 0;
	check = 1;
	ps->loop_a = ps->stack_a;
	while (ps->loop_a)
	{
		if (ps->loop_a->value <= key_nb)
		{
			if (i <= (size / 2) && check)
			{
				pos = i;
				check = 0;
			}
			else if (i > (size / 2) && (size - pos) < i)
				pos = i;
		}
		i++;
		ps->loop_a = ps->loop_a->next;
	}
	return (pos);
}

int	is_in_a(t_push_swap *ps, int value)
{
	ps->loop_a = ps->stack_a;
	while (ps->loop_a)
	{
		if (ps->loop_a->value == value)
			return (1);
		ps->loop_a = ps->loop_a->next;
	}
	return (0);
}

void	get_best_spot(t_push_swap *ps)
{
	if (ps->stack_b && ps->stack_b->next)
	{
		if (ps->stack_a && ps->stack_a->value < ps->stack_b->value && \
			ps->stack_a->value < ps->stack_b->next->value)
		{
			push(&ps->stack_a, &ps->stack_b, "pb\n");
			rotate(&ps->stack_b, "rb\n");
			return ;
		}
		else if (ps->stack_b->value < ps->stack_b->next->value)
			swap(&ps->stack_b, "sb\n");
	}
	push(&ps->stack_a, &ps->stack_b, "pb\n");
}

void	return_a(t_push_swap *ps)
{
	int		idx;
	int		j;
	int		i;

	i = ps->size - 1;
	j = ps->size;
	idx = 0;
	while (i)
	{
		ps->loop_b = ps->stack_b;
		idx = 0;
		while (ps->loop_b)
		{
			if (ps->loop_b->value == ps->tab[i])
			{
				pop_max(ps, idx, j);
				j--;
				break ;
			}
			idx++;
			ps->loop_b = ps->loop_b->next;
		}
		i--;
	}
	push(&ps->stack_b, &ps->stack_a, "pa\n");
}

int	get_dev(t_push_swap *ps)
{
	int	dev;

	if (ps->size < 11)
		dev = 2;
	else if (ps->size <= 80)
		dev = 4;
	else if (ps->size <= 100)
		dev = 6;
	else if (ps->size <= 200)
		dev = 9;
	else
		dev = 15;
	return (dev);
}
