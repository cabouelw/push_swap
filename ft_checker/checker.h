/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:53:33 by cabouelw          #+#    #+#             */
/*   Updated: 2021/07/06 17:47:11 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_check
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*loop_a;
	t_stack		*loop_b;
	t_stack		*tmp;
}	t_check;

void	s_swap_bonus(t_check *ps, int msg);
void	swap_bonus(t_stack **stack, char *msg);
void	rotate_bonus(t_stack **stack, char *msg);
void	rotate_r_bonus(t_stack **stack, char *msg);
void	push_bonus(t_stack **pop, t_stack **push, char *msg);
void	act_bonus(t_check *ps, char *input);
void	ft_splt_free(char	**splt);
void	checker_bonus(t_check *ps);
void	ft_free_bonus(t_stack **stack);
int		check_allnum_bonus(char *str);
void	ft_error_bonus(char *err, t_stack **stack);
void	ft_malloc_bonus(t_check *ps, char **str, int i);
int		check_lenvalue_bonus(char *str);
void	check_duplica_bonus(char *value, t_stack **stack);
void	ft_parsing_bonus(char **str, t_check *ps, int i, int j);

#endif