/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:35:48 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/06 17:33:13 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_bonus(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
	next = NULL;
	while (tmp)
	{
		next = tmp;
		tmp = tmp->next;
		free(next);
	}
}

int	check_allnum_bonus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_error_bonus(char *err, t_stack **stack)
{
	ft_putstr_fd(err, 2);
	if (*stack)
		ft_free_bonus(stack);
	exit(1);
}

void	ft_malloc_bonus(t_check *ps, char **str, int i)
{
	if (str[i])
	{
		check_duplica_bonus(str[i], &ps->stack_a);
		ps->tmp->next = (t_stack *)malloc(sizeof(t_stack) * 1);
		ps->tmp = ps->tmp->next;
		ps->tmp->next = NULL;
	}
}
