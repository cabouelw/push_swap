/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:48:20 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/02 17:18:52 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "../Libft/libft.h"

# define MIN_INT -2147483648

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	int			size;
	int			pos;
	int			*tab;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*loop_a;
	t_stack		*loop_b;
	t_stack		*min;
	t_stack		*tmp;
	t_stack		*max;
}	t_push_swap;

void	swap(t_stack **stack, char *msg);
void	s_swap(t_push_swap *ps, int msg);
void	rotate(t_stack **stack, char *msg);
void	rotate_r(t_stack **stack, char *msg);
void	push(t_stack **pop, t_stack **push, char *msg);
void	case_three(t_stack **stack_a);
void	case_five(t_push_swap *ps, int size, int idx);
void	case_more(t_push_swap *ps, int k, int i, int j);
int		check_allnum(char *str);
void	ft_free(t_stack **stack);
void	ft_error(char *err, t_stack **stack);
int		check_lenvalue(char *str);
void	check_duplica(char *value, t_stack **stack);
void	aff_stack(t_stack **stack_a, t_stack **stack_b, char *msg, int cn);
void	case_less(t_push_swap *ps);
void	case_100(t_push_swap *ps);
void	return_a(t_push_swap *ps);
int		get_dev(t_push_swap *ps);
void	ft_sort(t_push_swap *ps);
int		ft_sorted(t_push_swap *ps);
void	ft_tab_sort(t_push_swap *ps);
void	pop_max(t_push_swap *ps, int idx, int size);
void	get_best_spot(t_push_swap *ps);
int		get_close(t_push_swap *ps, int key_nb, int size);

#endif