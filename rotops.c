/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:08:01 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 18:09:35 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	idx = 0;
	tmp = stack->a[idx];
	idx++;
	while (idx < stack->size_a)
	{
		stack->a[idx - 1] = stack->a[idx];
		idx++;
	}
	stack->a[idx - 1] = tmp;
	if (check == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	idx = 0;
	tmp = stack->b[idx];
	idx++;
	while (idx < stack->size_b)
	{
		stack->b[idx - 1] = stack->b[idx];
		idx++;
	}
	stack->b[idx - 1] = tmp;
	if (check == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_a == 0 || stack->size_a == 1
		|| stack->size_b == 0 || stack->size_b == 1)
		return ;
	idx = 0;
	tmp = stack->a[idx];
	while (++idx < stack->size_a)
		stack->a[idx - 1] = stack->a[idx];
	stack->a[idx - 1] = tmp;
	idx = 0;
	tmp = stack->b[idx];
	while (++idx < stack->size_b)
		stack->b[idx - 1] = stack->b[idx];
	stack->b[idx - 1] = tmp;
	if (check == 0)
		write(1, "rr\n", 3);
}
