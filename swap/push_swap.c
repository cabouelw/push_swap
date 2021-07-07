/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:40:54 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/07 11:37:48 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_malloc(t_push_swap *ps, char **str, int i)
{
	if (str[i])
	{
		check_duplica(str[i], &ps->stack_a);
		ps->tmp->next = (t_stack *)malloc(sizeof(t_stack) * 1);
		ps->tmp = ps->tmp->next;
		ps->tmp->next = NULL;
	}
}

void	ft_free_splt(char **splt)
{
	int	i;

	i = 0;
	while (splt[i])
	{
		free(splt[i]);
		i++;
	}
	free(splt);
}

void	ft_parsing(char **str, t_push_swap *ps, int i, int j)
{
	char	**splt;

	ps->stack_a = (t_stack *)malloc(sizeof(t_stack) * 1);
	ps->tmp = ps->stack_a;
	while (str[i])
	{
		ps->tmp->next = NULL;
		splt = ft_split(str[i], ' ');
		j = 0;
		while (splt[j])
		{
			if (check_allnum(splt[j]) || check_lenvalue(splt[j]))
				ft_error("Error\n", &ps->stack_a);
			ps->tmp->value = ft_atoi(splt[j]);
			ps->size++;
			j++;
			ft_malloc(ps, splt, j);
		}
		ft_free_splt(splt);
		i++;
		ft_malloc(ps, str, i);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	ps.size = 0;
	if (argc >= 2)
	{
		ps.stack_a = NULL;
		ps.stack_b = NULL;
		ft_parsing(argv, &ps, 1, 0);
		ft_tab_sort(&ps);
		if (ps.size == 2)
			swap(&ps.stack_a, "sa\n");
		else if (ps.size == 3)
			case_three(&ps.stack_a);
		else if (ps.size == 5)
			case_five(&ps, 0, 0);
		else if (ps.size < 20)
			case_less(&ps);
		else
			case_more(&ps, 0, -1, 0);
		ft_free(&ps.stack_a);
		free(ps.tab);
		ft_free(&ps.stack_b);
	}
	return (0);
}
