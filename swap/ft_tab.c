/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:50:07 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 17:17:52 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_push_swap *ps)
{
	ps->tmp = ps->stack_a;
	while (ps->tmp)
	{
		if (ps->tmp->next && ps->tmp->value < ps->tmp->next->value)
			ps->tmp = ps->tmp->next;
		else if (!ps->tmp->next)
		{
			ft_free(&ps->stack_a);
			return (1);
		}
		else if (ps->tmp->next && ps->tmp->value > ps->tmp->next->value)
			break ;
	}
	return (0);
}

void	ft_sort(t_push_swap *ps)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ps->size)
	{
		j = 0;
		while (j < ps->size)
		{
			if (ps->tab[j] > ps->tab[i])
			{
				tmp = ps->tab[i];
				ps->tab[i] = ps->tab[j];
				ps->tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_tab_sort(t_push_swap *ps)
{
	int	i;

	i = 0;
	ps->tab = (int *)malloc((sizeof(int) * ps->size) + 1);
	ps->loop_a = ps->stack_a;
	while (i < ps->size)
	{
		ps->tab[i++] = ps->loop_a->value;
		ps->loop_a = ps->loop_a->next;
	}
	if (ft_sorted(ps))
		exit(0);
	ft_sort(ps);
}
