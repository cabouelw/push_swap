/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:55:59 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 16:32:02 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop_max(t_push_swap *ps, int idx, int size)
{
	int	i;
	int	cn;

	i = 0;
	cn = 0;
	if (idx == 1)
	{
		swap(&ps->stack_b, "sb\n");
		push(&ps->stack_b, &ps->stack_a, "pa\n");
		return ;
	}
	while (i < idx && idx < (size / 2))
	{
		rotate(&ps->stack_b, "rb\n");
		i++;
		cn++;
	}
	i = size;
	while (i > idx && idx >= (size / 2))
	{
		rotate_r(&ps->stack_b, "rrb\n");
		i--;
		cn++;
	}
	push(&ps->stack_b, &ps->stack_a, "pa\n");
}

void	ft_swap_top(t_push_swap *ps)
{
	if (ps->stack_b && ps->stack_b->next && \
		ps->stack_b->value < ps->stack_b->next->value)
		s_swap(ps, 1);
	else
		swap(&ps->stack_a, "sa\n");
}

void	less_act(t_push_swap *ps, int pos, int size)
{
	int	i;

	i = 0;
	if (pos <= (size / 2))
	{
		if (pos == 1)
			ft_swap_top(ps);
		else
		{
			while (pos)
			{
				rotate(&ps->stack_a, "ra\n");
				pos--;
			}
		}
	}
	else if (pos > (size / 2))
	{
		while (pos < size)
		{
			rotate_r(&ps->stack_a, "rra\n");
			pos++;
		}
	}
	get_best_spot(ps);
}

int	*medium(t_push_swap *ps, int dev, int i)
{
	int	*med;
	int	l;

	med = (int *)malloc(sizeof(int) * dev);
	l = (ps->size / dev);
	while (i < dev)
	{
		med[i] = ps->tab[l - 1];
		l = l + (ps->size / dev);
		i++;
	}
	return (med);
}

void	case_more(t_push_swap *ps, int k, int i, int j)
{
	int	dev;
	int	pos;
	int	*med;

	dev = get_dev(ps);
	med = medium(ps, dev, 0);
	while (++i < dev)
	{
		j = 0;
		while (j < (ps->size / dev))
		{
			pos = get_close(ps, med[i], ps->size - k);
			less_act(ps, pos, ps->size - k);
			k++;
			j++;
		}
	}
	ps->loop_a = ps->stack_a;
	while (ps->loop_a)
	{
		push(&ps->stack_a, &ps->stack_b, "pb\n");
		ps->loop_a = ps->loop_a->next;
	}
	free(med);
	return_a(ps);
}
