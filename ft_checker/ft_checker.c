/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:41:21 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 16:38:23 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_splt_free(char	**splt)
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

void	act_bonus(t_check *ps, char *input)
{
	if (!ft_strcmp(input, "pa"))
		push_bonus(&ps->stack_b, &ps->stack_a, NULL);
	else if (!ft_strcmp(input, "pb"))
		push_bonus(&ps->stack_a, &ps->stack_b, NULL);
	else if (!ft_strcmp(input, "sa"))
		swap_bonus(&ps->stack_a, NULL);
	else if (!ft_strcmp(input, "sb"))
		swap_bonus(&ps->stack_b, NULL);
	else if (!ft_strcmp(input, "ss"))
		s_swap_bonus(ps, 0);
	else if (!ft_strcmp(input, "ra"))
		rotate_bonus(&ps->stack_a, NULL);
	else if (!ft_strcmp(input, "rb"))
		rotate_bonus(&ps->stack_b, NULL);
	else if (!ft_strcmp(input, "rra"))
		rotate_r_bonus(&ps->stack_a, NULL);
	else if (!ft_strcmp(input, "rrb"))
		rotate_r_bonus(&ps->stack_b, NULL);
	else if (!ft_strcmp(input, "rrr"))
	{
		rotate_r_bonus(&ps->stack_a, NULL);
		rotate_r_bonus(&ps->stack_b, NULL);
	}
	else
		ft_error_bonus("Error\n", &ps->stack_a);
}

void	checker_bonus(t_check *ps)
{
	int		i;
	char	*input;

	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &input);
		if (*input == '\0')
			break ;
		act_bonus(ps, input);
		free(input);
	}
	ps->tmp = ps->stack_a;
	while (ps->tmp)
	{
		if (ps->tmp->next && ps->tmp->value < ps->tmp->next->value)
			ps->tmp = ps->tmp->next;
		else if (ps->tmp->next)
			ft_error_bonus("KO\n", &ps->stack_a);
		else
			break ;
	}
	if (ps->stack_b)
		ft_error_bonus("KO\n", &ps->stack_b);
}

int	main(int argc, char **argv)
{
	t_check	ps;

	if (argc < 2)
		return (0);
	ft_parsing_bonus(argv, &ps, 1, 0);
	checker_bonus(&ps);
	ft_putstr_fd("OK\n", 1);
	return (0);
}
