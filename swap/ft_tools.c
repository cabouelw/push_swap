/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:40:22 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/04 13:28:25 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_allnum(char *str)
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

void	ft_free(t_stack **stack)
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

void	ft_error(char *err, t_stack **stack)
{
	ft_putstr_fd(err, 2);
	if (*stack)
		ft_free(stack);
	exit(1);
}

int	check_lenvalue(char *str)
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

void	check_duplica(char *value, t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		if (ft_atoi(value) == tmp->value)
			ft_error("Error\n", stack);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}
