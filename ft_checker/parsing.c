/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:37:39 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/04 13:26:57 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_lenvalue_bonus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_atoi(str + i) > 2147483647 || ft_atoi(str + i) < -2147483648)
		return (1);
	return (0);
}

void	check_duplica_bonus(char *value, t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		if (ft_atoi(value) == tmp->value)
			ft_error_bonus("Error\n", stack);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

void	ft_parsing_bonus(char **str, t_check *ps, int i, int j)
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
			if (check_allnum_bonus(splt[j]) || check_lenvalue_bonus(splt[j]))
				ft_error_bonus("Error\n", &ps->stack_a);
			ps->tmp->next = NULL;
			ps->tmp->value = ft_atoi(splt[j]);
			j++;
			ft_malloc_bonus(ps, splt, j);
		}
		ft_splt_free(splt);
		i++;
		ft_malloc_bonus(ps, str, i);
	}
}
