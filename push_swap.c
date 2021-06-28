/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:40:54 by cabouelw          #+#    #+#             */
/*   Updated: 2021/06/28 20:26:35 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int		check_allnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void ft_free(t_stack **stack)
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
	int i;

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
		return;
	tmp = *stack;
	// printf("\n");
	while (tmp)
	{
		// printf("|%ld|%d|\n", ft_atoi(value), tmp->value);
		if (check_lenvalue(value))
			ft_error("Error Int!!!\n", stack);
		if (ft_atoi(value) == tmp->value)
			ft_error("Error duplicates!!!\n", stack);
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
}

void	check_quotation(char **str, int argc, t_stack **stack)
{
	int		i;
	int		j;
	char	**splt;
	t_stack	*tmp;

	i = 1;
	(void)argc;
	*stack = (t_stack*)malloc(sizeof(t_stack) * 1);
	tmp = *stack;
	while (str[i])
	{
		tmp->next = NULL;
		splt = ft_split(str[i], ' ');
		j = 0;
		while (splt[j])
		{
			if (check_allnum(splt[j]))
				ft_error("only numbers!!!\n", stack);
			tmp->next = NULL;
			tmp->value = ft_atoi(splt[j]);
			j++;
			if (splt[j])
			{
				check_duplica(splt[j], stack);
				tmp->next = (t_stack*)malloc(sizeof(t_stack) * 1);
				tmp = tmp->next;
			}
		}
		i++;
		if (str[i])
		{
			check_duplica(str[i], stack);
			tmp->next = (t_stack*)malloc(sizeof(t_stack) * 1);
			tmp = tmp->next;
		}
	}
}

void	aff_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *loop;
	t_stack *loop_b;

	loop = stack_a;
	loop_b = stack_b;
	printf("\n---------------------------------\n");
	printf("a|-----------|b\n");
	printf(" \n");
	while(loop)
	{
		printf("%i|-----------|", loop->value);
		if (loop_b)
		{
			printf("%d", loop_b->value);
			loop_b = loop_b->next;
		}
		printf("\n");
		loop = loop->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;


    if (argc < 2)
		ft_putstr_fd("args!!!\n", 2);
	else
	{
		stack_a = NULL;
		stack_b = NULL;
		check_quotation(argv, argc, &stack_a);
		printf("befoor/////////////////////////////%d\n", argc);
		aff_stack(stack_a, stack_b); 					// Affichage
		

		if (argc < 5)
			case_three(&stack_a);
		else
			push_and_swap(&stack_a, &stack_b);


		printf("after-----%d\n", argc);
		aff_stack(stack_a, stack_b);			// Affichage
		
		ft_free(&stack_a);
	}
    return(0);
}

// rotate_r(&stack_a, "rra\n");
// push(&stack_a, &stack_b, "pb\n");
// push(&stack_a, &stack_b, "pb\n");
// push(&stack_b, &stack_a, "pa\n");
// rotate(&stack_a, "ra\n");
// swap(&stack_a, "sa\n");
// printf("-----\n");