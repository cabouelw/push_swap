/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:33:03 by cabouelw          #+#    #+#             */
/*   Updated: 2021/06/28 19:46:18 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include"Libft/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void	swap(t_stack **stack, char *msg);
void	rotate(t_stack **stack, char *msg);
void	rotate_r(t_stack **stack, char *msg);
void	push(t_stack **pop, t_stack **push, char *msg);
void	case_three(t_stack **stack_a);
void	push_and_swap(t_stack **stack_a, t_stack **stack_b);
void	aff_stack(t_stack *stack_a, t_stack *stack_b);